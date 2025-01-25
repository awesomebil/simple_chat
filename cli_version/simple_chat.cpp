#include "message_server.h"

int main(int argc, char* argv[]) {
    message_server m;
    int c;

    while ((c = getopt(argc, argv, "46s:c:p:v")) != -1)
    {
        switch (c)
        {
        case '4':
            m.set_ipv6(false);
            break;
        
        case '6':
            m.set_ipv6(true);
            break;
        
        case 's':
            m.set_address(optarg);
            m.set_is_client(false);
            break;
        
        case 'c':
            m.set_address(optarg);
            m.set_is_client(true);
            break;
        
        case 'p':
            m.set_port(atoi(optarg));
            break;

        case 'v':
            m.set_debug_flag(true);
            break;
        
        default:
            cout << "Error parsing command line options..." << endl;
            exit(0);
            break;
        }
    }

    if (m.get_is_client())
    {
        m.setup_client();
    } else {
        m.setup_server();
    }   

    return 0;
}