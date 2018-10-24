#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <linux/types.h> 
#include <dirent.h>

struct stat {
	dev_t	st_dev;			/* device inode resides on */
	ino_t st_ino;			/* inode's number */
	mode_t st_mode;		/* inode protection mode */
	nlink_t st_nlink; /* number of hard links to the file */
	uid_t st_uid;			/* user-id of owner */
	gid_t st_gid;			/* group-id of owner */
	dev_t st_rdev;		/* device type, for special file inode */
	struct timespec st_atimespec; /* time of last access */
	struct timespec st_mtimespec; /* time of last data modification */
	struct timespec st_ctimespec; /* time of last file status change */
	off_t	st_size;		/* file size, in bytes */
	quad_t st_blocks; /* blocks allocated for file */
	u_long st_blksize;/* optimal file sys I/O ops blocksize */
	u_long st_flag;		/* user defined flags for file */
	u_long st_gen; 		/* file generation number */
};

struct mList{
	int amount;
	int value;
	char filename[32];
	mList* next;
};

int main(){
	// declare all stuff
	FILE* file_ptr;
	DIR* dir_ptr;
	struct dirent* dp;
	struct stat* stat_buf;
	// init list
	struct mList list_head;
	list_head.amount = 0;
	list_head.value = 0;
	list_head.next = NULL;
	list_head.filename = "";
	struct mList* list_ptr = &list_head;
	struct mList* allocator;
	// add some integer buffers
	int stats_checker, ino_t_value;
	
	dir_ptr = opendir("../tmp");
	if(dir_ptr == NULL){ return (ERROR); }
	// scan the directory
	while((dp = readdir(dir_ptr)) != NULL){
		// get stats.i_node from file
		stats_checker = stat(dp->d_name, stat_buf);
		ino_t_value = stat_buf->ino_t;
		
		// add it to the list
		list_ptr = &list_head;
		while(list_ptr != NULL){
			// found? good
			if(list_ptr->value == ino_t_value){
				list_ptr->amount += 1;
			} else {
				// not found and not finished? move.
				if(list_ptr->next != NULL){
					list_ptr = list_ptr->next;
				} else {
					// not found, finished? add new entry
					allocator = malloc(sizeof(int)*3 + sizeof(char)*32);
					list_ptr->next = allocator;
					allocator->amount = 1;
					allocator->value = ino_t_value;
					allocator->filename=dp->d_name;
				}
			}
		}
	}
	// after all ids found, print necessary units
	file_ptr = fopen("ex4.txt", "r+");
	list_ptr = &list_head;
	while(list_ptr != NULL){
		stats_checker = list_ptr->amount;
		if(stats_checker > 1){
			fputs(list_ptr->filename, file_ptr);
		}
		if(list_ptr->next != NULL){
			list_ptr = list_ptr->next;
		}
	}
	fclose(file_ptr);
	(void) closedir(dir_ptr);
	return 0;
}
