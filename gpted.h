/*
gpt.h
*/


/* https://en.wikipedia.org/wiki/GUID_Partition_Table#Partition_table_header_(LBA_1) */
typedef struct _GPT_HEADER {
  /* 00 0x00 */ unsigned char Signature[8];
  /* 08 0x08 */ unsigned char Revision[4];
  /* 12 0x0C */ unsigned char HeaderSize[4];
  /* 16 0x10 */ unsigned char Crc32Header[4];
  /* 20 0x14 */ unsigned char Reserved20[4];
  /* 24 0x18 */ unsigned char CurrentLBA[8];
  /* 32 0x20 */ unsigned char BackupLBA[8];
  /* 40 0x28 */ unsigned char FirstUsableLBA[8];
  /* 48 0x30 */ unsigned char LastUsableLBA[8];
  /* 56 0x38 */ unsigned char DiskGUID[16];
  /* 72 0x48 */ unsigned char StartingLBA[8];
  /* 80 0x50 */ unsigned char NumPartitionEntries[4];
  /* 84 0x54 */ unsigned char PartitionEntrySize[4];
  /* 88 0x58 */ unsigned char Crc32PartitionEntries[4];
  /* 92 0x5C */ unsigned char Reserved92[420 /* varies by sector size */];
} GPT_HEADER;


/* https://en.wikipedia.org/wiki/GUID_Partition_Table#Partition_entries_(LBA_2%E2%80%9333) */
typedef struct _GPT_PARTITION_ENTRY {
  /* 00 0x00 */ unsigned char PartitionTypeGUID[16];
  /* 16 0x10 */ unsigned char UniquePartitionGUID[16];
  /* 32 0x20 */ unsigned char FirstLBA[8];
  /* 40 0x28 */ unsigned char LastLBA[8];
  /* 48 0x30 */ unsigned char AttributeFlags[8];
  /* 56 0x38 */ unsigned char PartitionName[36];
} GPT_PARTITION_ENTRY;

#define GPT_ATTR_BIT00_PLATFORM			0
#define GPT_ATTR_BIT01_IGNORE			1
#define GPT_ATTR_BIT02_LEGACY_BIOS_BOOTABLE	2
#define GPT_ATTR_BIT60_MS_READ_ONLY		60
#define GPT_ATTR_BIT61_MS_SHADOW_COPY		61
#define GPT_ATTR_BIT62_MS_HIDDEN		62
#define GPT_ATTR_BIT63_MS_NO_DRIVE_LETTER	63
#define GPT_ATTR_BIT56_CHROME_OS_BOOT_SUCCESS	56
#define GPT_ATTR_BIT52_CHROME_OS_TRIES_LEFT	52
#define GPT_ATTR_BIT48_CHROME_OS_PRIORITY	48
