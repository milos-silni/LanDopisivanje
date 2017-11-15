#ifndef NITSLUSAJ_H_INCLUDED
#define NITSLUSAJ_H_INCLUDED

#include <winsock.h>

using namespace std;

class NitSlusaj : public wxThread{
    private:
        LanDopisivanjeFrame *m_landopisivanje;
        SOCKET sock;
        int Slusaj(){
            WSADATA wsaData;
            WSAStartup(MAKEWORD(1, 1), &wsaData);
            sock = socket(AF_INET, SOCK_DGRAM, 0);
            if (sock == INVALID_SOCKET) {
                WSACleanup();
                return 1;
            }
            SOCKADDR_IN mojaAdr, tudjaAdr;
            mojaAdr.sin_family = AF_INET;
            mojaAdr.sin_addr.s_addr = INADDR_ANY;
            mojaAdr.sin_port = htons(PORT);
            //memset(&(mojaAdr.sin_zero), '\0', 8); // ostatak strukture popuni nulama
            if(bind(sock, (struct sockaddr*)&mojaAdr, sizeof(struct sockaddr)) == SOCKET_ERROR){
                WSACleanup();
                return 1;
            }
            int addr_len = sizeof(struct sockaddr);
            int numbytes;
            while(1){
                S_Poruka buff;
                numbytes=recvfrom(sock, (char*)&buff, sizeof(S_Poruka), 0, (struct sockaddr *)&tudjaAdr, &addr_len);
                if (numbytes<0){
                    WSACleanup();
                    return 1;
                }
                MojCommandEvent event( wxEVT_MOJ_COMMAND_EVENT, 7779);
                event.SetString( wxString::FromAscii(inet_ntoa(tudjaAdr.sin_addr)) );
                event.SetPoruka(buff);
                wxPostEvent(m_landopisivanje, event);
            }
            closesocket(sock);
            WSACleanup();
            return 0;
        }

        int PORT;
    public:
        NitSlusaj( LanDopisivanjeFrame* m ){
            wxThread::Create();
            m_landopisivanje = m;
        }
        void *Entry(){
            Slusaj();
            return NULL;
        }
        void Set_PORT( int port ){
            PORT = port;
        }
};

#endif // NITSLUSAJ_H_INCLUDED

