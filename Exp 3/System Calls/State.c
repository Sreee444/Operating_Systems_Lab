#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

void main()
 {
   char Path[10];
   struct stat *nfile;
   nfile = (struct stat*) malloc (sizeof(struct stat));
   printf("Enter the Filename : ");
   scanf("%s",Path);
   stat(Path,nfile);
   printf("User id : %d\n",nfile -> st_uid);
   printf("Block Size : %ld\n",nfile -> st_blksize);
   printf("Product Mode : %d\n",nfile -> st_mode);
   printf("Last Access time : %ld\n",nfile -> st_atime);
   printf("Last Modified time : %ld\n",nfile -> st_mtime);
   printf("Size of the File : %ld\n",nfile -> st_size);
   printf("Number of Links : %ld\n",nfile -> st_nlink);
 }
