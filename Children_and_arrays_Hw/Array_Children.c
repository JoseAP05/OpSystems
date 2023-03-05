#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(){
	pid_t pid_A;
	pid_A = fork();
	
	int arrayN[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int arrayM[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	int fd, fd2, n_write, n_write2, m_read, m_read2;
	
	if(pid_A == 0)
   	{
      		//creating
      		fd = creat( "N.dat", 777);
      		if(fd < 0)
      		{
      			perror("error en creat");
      			exit(-1);
      		}
      		
      		n_write = write( fd, arrayN, sizeof(arrayN));
      		if(n_write < 0)
      		{
      			perror("error en write");
      			exit(-1);
      		}
      		
      		close(fd);
      		
      		return 0;
   	}
   
   
   	if(pid_A > 0)
   	{
      		pid_t pid_B;
      		pid_B = fork();
      		
      		if (pid_B == 0)
      		{
      			//creating
      			fd = creat( "M.dat", 777);
      			if(fd < 0)
      			{
      				perror("error en creat2");
      				exit(-1);
      			}
      		
      			n_write2 = write( fd, arrayM, sizeof(arrayM));
      			if(n_write2 < 0)
      			{
      				perror("error en write2");
      				exit(-1);
      			}
      		
      			close(fd);
      		
      			return 0;
      		
      		}
      		
      		
      		if(pid_B > 0)
      		{
      			sleep(3);
      			
      			int arrayRN[10];
      			int arrayRM[10];
      			int sumArray[10];
      			int i, j;
      			
      			fd = open("N.dat", 0);
      			fd2 = open("M.dat", 0);
      			
      			m_read = read( fd, arrayRN, sizeof(arrayRN));
      			m_read2 = read( fd, arrayRM, sizeof(arrayRM));
      			
      			for ( i = 0; i < 10; i++)
      			{
      				sumArray[i] = arrayRN[i] + arrayRM[i];
      			}
      			
      			for( j = 0; j < 10; j++)
      			{
      				printf("%d\n", sumArray[j]);
      			}
      			
      			close(fd);
      			close(fd2);
      			
      			return 0;
      		
      		}
      	}
}

