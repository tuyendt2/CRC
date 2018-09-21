#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MSB_CRC8    (0x07) 
unsigned char GetCRC8(unsigned char *pucBuf, unsigned short usLen);
int main(){
	unsigned char *pucBuf  = (unsigned char *)malloc(2*sizeof(unsigned char));
	*pucBuf = 0x33;
	*(pucBuf+1) = 0x22;
	unsigned short usLen = 2;
	unsigned char result = GetCRC8(pucBuf,usLen);
	return 0;
	}

unsigned char GetCRC8(unsigned char *pucBuf, unsigned short usLen)
{
    unsigned char *puc = pucBuf;
    unsigned char ucCrc;
    unsigned char ucBit;

    for(ucCrc = 0x00; usLen != 0; usLen--){
        ucCrc ^= *puc;
        puc++;
        for( ucBit =0; ucBit < 8; ucBit++ ){
            if( (ucCrc & 0x80) == 0x80 ){
                ucCrc <<= 1;
                ucCrc ^= MSB_CRC8;
            }
            else{
                ucCrc <<= 1;
            }
        }
    }
    return ucCrc;
}
