#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/soundcard.h>
#include <sys/time.h>
#include <net/if.h>
#include <netinet/ip_icmp.h>
#include <string.h>

/*
 * 获得本机MAC地址
 * 失败返回值小于0，成功返回0
 */
int getself_macaddr(unsigned char *macaddr)
{
	int 			sock;
	int			ret;
	struct ifreq		ifr; 

	sock = socket(AF_INET, SOCK_DGRAM, 0); 
	if(sock == -1) 
	{ 
		perror("socket error"); 
		return -1; 
	} 


	memset(macaddr, 0, sizeof(macaddr));
	memset(&ifr, 0, sizeof(ifr));
    	strcpy(ifr.ifr_name, "eth0");

	ret = ioctl(sock,SIOCGIFHWADDR,&ifr,sizeof(ifr));
	if(ret == 0)
	{
		memcpy(macaddr, ifr.ifr_hwaddr.sa_data, 6);

		 printf("[getself_macaddr]%02x-%02x-%02x-%02x-%02x-%02x\n",
            (unsigned char)ifr.ifr_hwaddr.sa_data[0],
            (unsigned char)ifr.ifr_hwaddr.sa_data[1],
            (unsigned char)ifr.ifr_hwaddr.sa_data[2],
            (unsigned char)ifr.ifr_hwaddr.sa_data[3],
            (unsigned char)ifr.ifr_hwaddr.sa_data[4],
            (unsigned char)ifr.ifr_hwaddr.sa_data[5]
            );
	}
	else
	{
		perror("ioctl error!\n");
	}
	
	close(sock);
	
	return ret;
}

int main()
{
	unsigned char macaddr[64];
	getself_macaddr(macaddr); // [getself_macaddr] 12-0A-FD-32-CD-FE
}