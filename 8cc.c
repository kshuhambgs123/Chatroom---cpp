#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include<pthread.h>


struct sockaddr_in server_addr, client_addr;
struct sockaddr_in t_server_addr, t_client_addr;
char server_message[2000], client_message[2000];
pthread_t send_m, rcv ;
int server_struct_length;
int make;

void *func1()
{
    
    do{
    
    	
    		//printf("Enter the message---");
    		fgets( client_message, sizeof(client_message), stdin );
    		if (sendto( make, client_message, strlen(client_message), 0, (struct sockaddr*)&server_addr, server_struct_length) < 0){
        		printf("Can't send\n");
        		return NULL;
    		}
    		memset(client_message,0,2000);
    		
    		//printf(" msg sent \n");
    		
    	
    }while(1);
    
    
    return NULL;
}

void *func2()
{
    
    do{
    
    	
    		if (recvfrom( make, client_message, sizeof(client_message), 0, (struct sockaddr*)&server_addr, &server_struct_length) < 0){
        		printf("Couldn't receive\n");
        		return NULL;
   		}
   		
   		printf("Msg recieved ====>> %s\n", client_message);
   		memset(client_message,0,2000);
    		
    	
    }while(1);
    
    
    return NULL;
}





int main(void){

	
	server_struct_length = sizeof(server_addr);
	
	
	make=socket( AF_INET, SOCK_DGRAM, 0 );
	
	
	server_addr.sin_family = AF_INET;
    	server_addr.sin_port = htons(2000);
    	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    	
    	client_addr.sin_family = AF_INET;
    	client_addr.sin_port = htons(2001);
    	client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    	
    	if(bind( make, (struct sockaddr*)&client_addr, sizeof(client_addr)) < 0){
        	printf("Couldn't bind to the port\n");
        	return -1;
    	}
    	
    	
    	
    	
    	
    	pthread_create(&send_m, NULL, &func1, NULL);
    	pthread_create(&rcv, NULL, &func2, NULL);
    	
    	
    	pthread_join(send_m, NULL);
 	pthread_join(rcv,NULL);
    	
    	
    	/*while(1){
    	
    		
    		printf("Enter the message---");
    		fgets( client_message, sizeof(client_message), stdin );
    		if (sendto( make, client_message, strlen(client_message), 0, (struct sockaddr*)&server_addr, server_struct_length) < 0){
        		printf("Can't send\n");
        		return -1;
    		}
    		
    		printf(" msg sent \n");
    		
    		
    		if (recvfrom( make, client_message, sizeof(client_message), 0, (struct sockaddr*)&server_addr, &server_struct_length) < 0){
        		printf("Couldn't receive\n");
        		return -1;
   		}
   		
   		printf("Msg from client: %s\n", client_message);
   		
   		
   		
   		printf("Enter the message---");
    		fgets( client_message, sizeof(client_message), stdin );
    		if (sendto( make, client_message, strlen(client_message), 0, (struct sockaddr*)&server_addr, server_struct_length) < 0){
        		printf("Can't send\n");
        		return -1;
    		}
    		
    		printf(" msg sent \n");
    		
    		
    		if (recvfrom( make, client_message, sizeof(client_message), 0, (struct sockaddr*)&t_server_addr, &server_struct_length) < 0){
        		printf("Couldn't receive\n");
        		return -1;
   		}
   		
   		printf("Msg from client: %s\n", client_message);
   		
   		
   		
   		
   		
    	
    	
    	
    	}*/





}
