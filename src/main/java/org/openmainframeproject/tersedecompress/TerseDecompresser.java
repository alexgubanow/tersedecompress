package org.openmainframeproject.tersedecompress;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.ByteBuffer;

abstract class TerseDecompresser implements AutoCloseable
{
	TerseBlockReader input;
	ByteBuffer record;
	DataOutputStream stream;
    final TerseHeader header;
    final boolean TextFlag;
    
    public abstract void decode() throws IOException;
    
    public static TerseDecompresser create(InputStream inputStream, OutputStream outputStream, boolean textMode) throws IOException
    {
        DataInputStream input = new DataInputStream(new BufferedInputStream(inputStream));
        TerseHeader header_rv = TerseHeader.CheckHeader(input);
        
        if (!header_rv.SpackFlag) {
        	return new NonSpackDecompresser(input, outputStream, header_rv, textMode);
        } else {
        	return new SpackDecompresser(input, outputStream, header_rv, textMode);
        }
    }
    
	public TerseDecompresser(InputStream instream, OutputStream outputStream, TerseHeader header, boolean textMode)
	{		
		this.header = header;
		this.TextFlag = textMode;
		this.input = new TerseBlockReader(instream);
		this.stream = new DataOutputStream(new BufferedOutputStream(outputStream));
		
        // Reserve enough space for the record buffer to avoid reallocations.
        // For variable-length records, we can have up to 32767 bytes.
		this.record = ByteBuffer.allocate(header.VariableFlag ? 32767 : (header.RecordLength * 2));
	}
	
    /* Write a new line to the output file*/
    public void endRecord() throws IOException 
    {
    	if (header.VariableFlag && !TextFlag)
    	{
    		// write a RDW
    		int recordlength = record.position() + 4;
    		int rdw = recordlength << 16;
    		stream.writeInt(rdw);
    	}
        if (TextFlag) {
            record.put((byte)0x0A);
        }
        stream.write(record.array(), 0, record.position());
        record.clear();
    }

    /*
     * Write some stuff to the output record
     */

    public void PutChar(int X) throws IOException {
        if (X == 0 && TextFlag && header.VariableFlag == true) {
            endRecord();
        } else if (X == Constants.RECORDMARK && header.VariableFlag == true) {
            endRecord();
        } else {
            if (record.capacity() == record.position()) {
                throw new IOException("Record size exceeds expected maximum. File may be corrupted or not a valid Terse file.");
            }
            record.put(TextFlag ? (byte) Constants.EbcToAsc[X - 1] : (byte) (X - 1));
            if (header.VariableFlag != true && (int) (record.position()) == header.RecordLength) {
                endRecord();
            }
        }
    }

	@Override
	public void close() throws Exception {
		if (record.position() > 0 || TextFlag && header.VariableFlag)
		{
			endRecord();
		}
		this.stream.close();
		this.input.close();
	}
}
