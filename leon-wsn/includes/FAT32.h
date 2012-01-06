#include <stdio.h>
#include "types.h"
#include "sd.h"

#define IF_SGOW_DATA	0
#define DBG_FAT32		1
/*
 ������¼�ṹ����
*/
struct PartRecord
{
    unsigned char Active;         //0x80��ʾ�˷�����Ч
    unsigned char StartHead;      //�����Ŀ�ʼͷ
    unsigned char StartCylSect[2];//��ʼ����������
    unsigned char PartType;       //��������
    unsigned char EndHead;        //�����Ľ���ͷ
    unsigned char EndCylSect[2];  //��������������
    unsigned char StartLBA[4];    //�����ĵ�һ������
    unsigned char Size[4];        //�����Ĵ�С
};

/*
 ��������������0��������������
*/
struct PartSector
{
    unsigned char PartCode[446]; //MBR����������
    struct PartRecord Part[4];      //4��������¼
    unsigned char BootSectSig0;
    unsigned char BootSectSig1;
};

struct FAT32_FAT_Item
{
    unsigned char Item[4];
};

struct FAT32_FAT
{
    struct FAT32_FAT_Item Items[128];
};

/*
 FAT32�ж�BPB�Ķ�������  һ��ռ��90���ֽ�
*/
struct FAT32_BPB
{
    unsigned char BS_jmpBoot[3];     //��תָ��            offset: 0
    unsigned char BS_OEMName[8];     //                    offset: 3
    unsigned char BPB_BytesPerSec[2];//ÿ�����ֽ���        offset:11
    unsigned char BPB_SecPerClus[1]; //ÿ��������          offset:13
    unsigned char BPB_RsvdSecCnt[2]; //����������Ŀ        offset:14
    unsigned char BPB_NumFATs[1];    //�˾���FAT����       offset:16
    unsigned char BPB_RootEntCnt[2]; //FAT32Ϊ0            offset:17
    unsigned char BPB_TotSec16[2];   //FAT32Ϊ0            offset:19
    unsigned char BPB_Media[1];      //�洢����            offset:21
    unsigned char BPB_FATSz16[2];    //FAT32Ϊ0            offset:22
    unsigned char BPB_SecPerTrk[2];  //�ŵ�������          offset:24
    unsigned char BPB_NumHeads[2];   //��ͷ��              offset:26
    unsigned char BPB_HiddSec[4];    //FAT��ǰ��������     offset:28
    unsigned char BPB_TotSec32[4];   //�þ���������        offset:32

    unsigned char BPB_FATSz32[4];    //һ��FAT��������     offset:36
    unsigned char BPB_ExtFlags[2];   //FAT32����           offset:40
    unsigned char BPB_FSVer[2];      //FAT32����           offset:42
    unsigned char BPB_RootClus[4];   //��Ŀ¼�غ�          offset:44
    unsigned char FSInfo[2];         //��������FSINFO������offset:48
    unsigned char BPB_BkBootSec[2];  //ͨ��Ϊ6             offset:50
    unsigned char BPB_Reserved[12];  //��չ��              offset:52
    unsigned char BS_DrvNum[1];      //                    offset:64
    unsigned char BS_Reserved1[1];   //                    offset:65
    unsigned char BS_BootSig[1];     //                    offset:66
    unsigned char BS_VolID[4];       //                    offset:67
    unsigned char BS_FilSysType[11]; //	                offset:71
    unsigned char BS_FilSysType1[8]; //"FAT32    "         offset:82
};

// Structure of a dos directory entry.
#define DIR_NAME_LEN	8
struct direntry
{
    unsigned char deName[8];       // filename, blank filled
    unsigned char deExtension[3]; 	// extension, blank filled
    unsigned char deAttributes;   	// file attributes
    unsigned char deLowerCase;    	// NT VFAT lower case flags  (set to zero)
    unsigned char deCHundredth;   	// hundredth of seconds in CTime
    unsigned char deCTime[2];     	// create time
    unsigned char deCDate[2];     	// create date
    unsigned char deADate[2];     	// access date
    unsigned char deHighClust[2];     // high unsigned chars of cluster number
    unsigned char deMTime[2];     	// last update time
    unsigned char deMDate[2];     	// last update date
    unsigned char deLowCluster[2]; 	// starting cluster of file
    unsigned char deFileSize[4];      // size of file in unsigned chars
};

// Stuctures
#define FILE_NAME_LEN	64
struct FileInfoStruct
{
    unsigned char  FileName[12];
    unsigned long  FileStartCluster;			//< file starting cluster for last file accessed
    unsigned long  FileCurCluster;
    unsigned long  FileNextCluster;
    unsigned long  FileSize;					//< file size for last file accessed
    unsigned char  FileAttr;					//< file attr for last file accessed
    unsigned short FileCreateTime;			//< file creation time for last file accessed
    unsigned short FileCreateDate;			//< file creation date for last file accessed
    unsigned short FileMTime;
    unsigned short FileMDate;
    unsigned long  FileSector;				    //<file record place
    unsigned int   FileOffset;				    //<file record offset
};

/*
  FAT32��ʼ��ʱ��ʼ����װ�����½ṹ����
*/
struct FAT32_Init_Arg
{
    unsigned char BPB_Sector_No;   //BPB����������
    unsigned long Total_Size;            //���̵�������
    unsigned long FirstDirClust;       //��Ŀ¼�Ŀ�ʼ��
    unsigned long FirstDataSector;	 //�ļ����ݿ�ʼ������
    unsigned int  BytesPerSector;	 //ÿ���������ֽ���
    unsigned int  FATsectors;            //FAT����ռ������
    unsigned int  SectorsPerClust;	 //ÿ�ص�������
    unsigned long FirstFATSector;	 //��һ��FAT����������
    unsigned long FirstDirSector;	 //��һ��Ŀ¼��������
    unsigned long RootDirSectors;	 //��Ŀ¼��ռ������
    unsigned long RootDirCount;	 //��Ŀ¼�µ�Ŀ¼���ļ���
};

//�ļ�Ŀ¼�ָ���';'
//#define FIND_BPB_UP_RANGE 2000  //BPB��һ����0��������0��FINE_BPB_UP_RANGE��������ɨ��

void FAT32_Test();

/*end of file*/

