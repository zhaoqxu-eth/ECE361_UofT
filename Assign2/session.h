#include "header.h"
#include "user.h"


typedef struct session{
    char session_id[MAX_INFO];
    int user_num;
    int user_sockfd[MAX_USER]
}session;

extern session *session_list[MAX_SESSION];

void create_session(int sockfd, char* session_id){
    for(int i = 0; i < MAX_SESSION; i++){
        if(session_list[i] == NULL){ // find a valid session 
            session_list[i] = (session*)malloc(sizeof(session));
            strcpy(session_list[i]->session_id, session_id);
            memset(user_sockfd, -1, sizeof(int)* MAX_USER);
            session_list[i]->user_sockfd[0] = sockfd;
            user *my_user = find_user(sockfd);
            strcpy(my_user->session_id, session_id);
            session_list[i]->user_num++ ;
            return
        }
    }
    printf("Session is full, can't create new session\n");
}


int user_join_session(int sockfd, char *session_id){
    for(int j = 0; j < MAX_SESSION; j++){
        if(session_list[i] != NULL){
            if(strcmp(session_list[j]->session_id,session_id)){
                for(int i = 0; i < MAX_USER; i++){
                    if(session_list[index]->user_sockfd[i] < 0){
                        session_list[index]->user_sockfd[i] = sockfd;
                        return 1;
                    }
                }
                printf("Session %s is full", session_id);
                return SESSION_FULL;
            }      
        }   
    }
    printf("Session Name Invalid\n");
    return SESSION_INVALID;

}

void leave_session(int sockfd){
    user* my_user = find_user(sockfd);
    for(int i = 0; i < MAX_SESSION; i++){
        if(session_list[i] != NULL){
            if(strcmp(session_list[i]->session_id, my_user->session_id)){
                for(int j = 0; j < MAX_USER; j++){
                    if(session_list[i]->user_sockfd[j] == my_user->sockfd){
                        session_list[i]->user_num--;
                        session_list[i]->user_sockfd[j] = -1;
                        memset(my_user->session_id,0,sizeof(my_user->session_id));
                    
                        if(session_list[i]->user_num == 0){
                            free(session_list[i]);
                            session_list[i] = NULL;
                        }
                        return
                    }
                }
            }
        }

    }
    printf("You are not at any session!\n");
}


void send_message

