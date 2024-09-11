#include <stdbool.h>
#include <stdio.h>
#include <string.h>

short regs;
char memory[10000];

char sbox[256] = {
    0x48, 0x5c, 0xbc, 0x97, 0x81, 0x91, 0x60, 0xad, 0x94, 0xcb, 0x92, 0x39,
    0x1a, 0x0f, 0x30, 0x2d, 0x45, 0xde, 0x14, 0xa2, 0x08, 0x57, 0xb6, 0xae,
    0x76, 0x8e, 0x87, 0x15, 0x0c, 0xe7, 0x62, 0xc8, 0x58, 0x29, 0x6d, 0xc9,
    0xa7, 0xbe, 0x04, 0x49, 0x05, 0xfa, 0x75, 0x9f, 0xfd, 0x95, 0xbb, 0x5b,
    0x79, 0xbf, 0xda, 0xeb, 0x21, 0x9b, 0xa5, 0x82, 0x3a, 0x3e, 0xb9, 0x99,
    0xf0, 0xf5, 0x6b, 0x06, 0xfc, 0xaf, 0xf2, 0xb0, 0x78, 0x86, 0xcf, 0xd4,
    0x83, 0x59, 0x00, 0x4a, 0xb5, 0xfe, 0xab, 0x3d, 0xc7, 0x8c, 0xe3, 0xc3,
    0xe5, 0x03, 0x5a, 0x1d, 0x9d, 0x1f, 0x0a, 0x56, 0xc0, 0xba, 0x43, 0x25,
    0x77, 0x24, 0x7c, 0xa6, 0xdf, 0xf1, 0x4b, 0x44, 0xff, 0x4c, 0xaa, 0xc1,
    0x69, 0xf9, 0x38, 0x88, 0x9a, 0xa4, 0xe6, 0x10, 0xdc, 0xea, 0x68, 0x8d,
    0x5f, 0x63, 0xbd, 0x8b, 0xf3, 0x7e, 0xdb, 0x73, 0x5d, 0x65, 0x67, 0xa1,
    0x72, 0xd8, 0xb1, 0x1b, 0x9e, 0x84, 0x16, 0x32, 0xe1, 0xf4, 0xef, 0x93,
    0xac, 0x74, 0x36, 0x8f, 0xcc, 0x61, 0x0d, 0x35, 0x12, 0xdd, 0x4e, 0xc4,
    0x64, 0x3f, 0x09, 0x70, 0x2a, 0xfb, 0xc5, 0x85, 0x3b, 0x1c, 0x50, 0x19,
    0xd5, 0xe9, 0x47, 0x0b, 0xe2, 0xca, 0xc6, 0xf7, 0xb2, 0xd6, 0xf8, 0x11,
    0x54, 0x6e, 0x90, 0xc2, 0xec, 0x96, 0x51, 0xd7, 0xe8, 0x31, 0x80, 0x7d,
    0x18, 0x34, 0xb7, 0x02, 0xa0, 0x7a, 0xb3, 0xd0, 0x46, 0x66, 0x37, 0x1e,
    0x7b, 0x42, 0x6c, 0x17, 0xd9, 0x33, 0x2b, 0x22, 0xce, 0xa9, 0x7f, 0xb4,
    0x07, 0x6a, 0x41, 0x40, 0x26, 0x2f, 0xa8, 0xcd, 0x71, 0xb8, 0x53, 0x13,
    0x5e, 0xf6, 0xe0, 0x52, 0x4f, 0x6f, 0xe4, 0x89, 0x3c, 0x9c, 0xa3, 0x8a,
    0x4d, 0x28, 0x0e, 0xd3, 0xd2, 0x98, 0xee, 0x2c, 0x2e, 0xed, 0x27, 0x20,
    0x01, 0x23, 0x55, 0xd1,

};

void runnnn(long param_1)

{
  int iVar1;
  int iVar2;
  char bVar3;
  char bVar4;
  bool bVar5;
  int local_10;

  local_10 = 0;
  bVar5 = true;
  while (bVar5) {
    iVar1 = local_10 + 1;
    switch (*(char *)(param_1 + local_10)) {
    case 0:
      printf("0");
      iVar2 = local_10 + 2;
      local_10 = local_10 + 3;
      *(char *)((long)&regs +
                (long)(int)(unsigned int)*(char *)(param_1 + iVar1)) =
          *(char *)(iVar2 + param_1);
      break;
    case 1:
      printf("1");
      iVar2 = local_10 + 2;
      local_10 = local_10 + 3;
      *(char *)((long)&regs +
                (long)(int)(unsigned int)*(char *)(param_1 + iVar1)) =
          *(char *)((long)&regs +
                    (long)(int)(unsigned int)*(char *)(param_1 + iVar1)) ^
          *(char *)((long)&regs +
                    (long)(int)(unsigned int)*(char *)(param_1 + iVar2));
      break;
    case 2:
      printf("2");
      iVar2 = local_10 + 2;
      bVar3 = *(char *)(param_1 + iVar1);
      local_10 = local_10 + 3;
      bVar4 = *(char *)(param_1 + iVar2);
      *(char *)((long)&regs + (long)(int)(unsigned int)bVar3) =
          *(char *)((long)&regs + (long)(int)(unsigned int)bVar3)
              << (bVar4 & 0x1f) |
          (char)((int)(unsigned int)*(char *)((long)&regs +
                                              (long)(int)(unsigned int)bVar3) >>
                 (8 - bVar4 & 0x1f));
      break;
    case 3:
      printf("3");
      local_10 = local_10 + 2;
      *(char *)((long)&regs +
                (long)(int)(unsigned int)*(char *)(param_1 + iVar1)) =
          sbox[(int)(unsigned int)*(
              char *)((long)&regs +
                      (long)(int)(unsigned int)*(char *)(param_1 + iVar1))];
      break;
    case 4:
      printf("4");
      iVar2 = local_10 + 2;
      local_10 = local_10 + 3;
      memory[(int)(unsigned int)*(char *)(param_1 + iVar2)] =
          *(char *)((long)&regs +
                    (long)(int)(unsigned int)*(char *)(param_1 + iVar1));
      break;
    case 5:
      printf("5");
      iVar2 = local_10 + 2;
      local_10 = local_10 + 3;
      *(char *)((long)&regs +
                (long)(int)(unsigned int)*(char *)(param_1 + iVar1)) =
          memory[(int)(unsigned int)*(char *)(param_1 + iVar2)];
      break;
    case 6:
      printf("6");
      local_10 = local_10 + 2;
      putchar((unsigned int)*(
          char *)((long)&regs +
                  (long)(int)(unsigned int)*(char *)(param_1 + iVar1)));
      break;
    case 7:
      printf("7");
      bVar5 = false;
      local_10 = iVar1;
      break;
    case 8:
      printf("8");
      bVar3 = *(char *)(param_1 + iVar1);
      bVar4 = *(char *)(param_1 + (local_10 + 2));
      *(char *)((long)&regs + (long)(int)(unsigned int)bVar3) =
          (char)((int)(unsigned int)*(char *)((long)&regs +
                                              (long)(int)(unsigned int)bVar3) >>
                 (bVar4 & 0x1f)) |
          *(char *)((long)&regs + (long)(int)(unsigned int)bVar3)
              << (8 - bVar4 & 0x1f);
      local_10 = local_10 + 3;
      break;
    default:
      puts("Invalid instruction");
      bVar5 = false;
      local_10 = iVar1;
    }
  }
  return;
}

void washing_machine(char *param_1, unsigned long param_2) {
  char bVar1;
  char local_1b;
  unsigned long local_18;
  unsigned long local_10;

  local_1b = *param_1;
  for (local_18 = 1; local_18 < param_2; local_18 = local_18 + 1) {
    local_1b = param_1[local_18] ^ local_1b;
    param_1[local_18] = local_1b;
  }
  for (local_10 = 0; local_10 < param_2 >> 1; local_10 = local_10 + 1) {
    bVar1 = param_1[local_10];
    param_1[local_10] = param_1[(param_2 - local_10) + -1];
    param_1[(param_2 - local_10) + -1] = bVar1;
  }
  return;
}

int main(int argc, char **argv) {

  int iStack_12760, iStack_12764, iStack_12768, iVar5, iVar1, iVar2;
  char local_2728[10008];
  char *pcVar7 = argv[1];
  long local_10;
  size_t sVar6;
  int local_272d = 0xddccbbaa;
  char local_2729 = 0xee;

  sVar6 = strlen(pcVar7);
  iVar5 = (int)sVar6;
  iStack_12768 = 0;

  washing_machine(pcVar7, iVar5);

  for (iStack_12764 = 0; iStack_12764 < iVar5;
       iStack_12764 = iStack_12764 + 1) {
    local_2728[iStack_12768] = '\0';
    iVar1 = iStack_12768 + 2;
    local_2728[iStack_12768 + 1] = '\x01';
    iStack_12768 = iStack_12768 + 3;
    local_2728[iVar1] = pcVar7[iStack_12764];
    for (iStack_12760 = 0; iStack_12760 < 10; iStack_12760 = iStack_12760 + 1) {
      local_2728[iStack_12768] = '\0';
      local_2728[iStack_12768 + 1] = '\0';
      local_2728[iStack_12768 + 2] =
          *(char *)((long)&local_272d +
                    (long)((iStack_12760 + iStack_12764 * 10) % 5));
      local_2728[iStack_12768 + 3] = '\b';
      local_2728[iStack_12768 + 4] = '\x01';
      local_2728[iStack_12768 + 5] = '\x03';
      local_2728[iStack_12768 + 6] = '\x03';
      local_2728[iStack_12768 + 7] = '\x01';
      local_2728[iStack_12768 + 8] = '\x01';
      local_2728[iStack_12768 + 9] = '\x01';
      local_2728[iStack_12768 + 10] = '\0';
      local_2728[iStack_12768 + 0xb] = '\x02';
      iVar1 = iStack_12768 + 0xd;
      local_2728[iStack_12768 + 0xc] = '\x01';
      iStack_12768 = iStack_12768 + 0xe;
      local_2728[iVar1] = '\x03';
    }
    local_2728[iStack_12768] = '\x04';
    iVar1 = iStack_12768 + 2;
    local_2728[iStack_12768 + 1] = '\x01';
    iStack_12768 = iStack_12768 + 3;
    local_2728[iVar1] = (char)iStack_12764;
  }
  local_2728[iStack_12768] = '\a';

  runnnn((long)local_2728);

  // printf("%s\n", memory);
}
