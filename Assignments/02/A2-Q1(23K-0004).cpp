#include <iostream>
using namespace std;

class SecurityTool{
protected:
	string securityLevel;
	float cost;
	int numberOfDevices;
	
public:
	SecurityTool(const string& level, float cost, int devices){
		securityLevel = level;
		if(cost > 0){
			this->cost = cost;
		} else{
			cout << "Enter a valid positive value" << endl;
		}
		numberOfDevices = devices;
	}
	
	void performScan(){
		cout << "Performing generic security scan..." << endl;
		cout << "Cost: " << cost << endl;
		cout << "Allowed devices: " << numberOfDevices << endl;
	}
};

class FirewallTool: public SecurityTool{
private:
	int Ports[30];
	string Protocols[8];
	
public:
	FirewallTool(const string& level, float cost, int devices): SecurityTool(level, cost, 10){
		const int portNumber = 4;
		void generatelist(int portNumber);
		
		Protocols[0] = "HTTPS";
        Protocols[1] = "FTP";
        Protocols[2] = "UDP";
        Protocols[3] = "ICMP";
        Protocols[4] = "SSH";
        Protocols[5] = "SNMP";
        Protocols[6] = "TCP";
        Protocols[7] = "DNS";
	}
	
	void generatelist(int portNumber){
		for(int i = 0; i < 30; i++){
			Ports[i] = portNumber + i + 1;
		}
		
	}
	
	void performScan(){
		SecurityTool::performScan();
		if(securityLevel == "High"){
			cout << "Traffic Allowed from the following: " << endl;
			cout << "PORTS: " << endl;
			for(int i = 0; i < 23; i++){
				cout << "Port Number: " << Ports[i] << endl;
			}
			cout << "PROTOCOLS: " << endl;
			for(int i = 0; i < 6; i++){
				cout << Protocols[i] << endl;
			}
			cout << endl << endl;
		}
		
		if(securityLevel == "Medium"){
			cout << "Traffic Allowed from the following: " << endl;
			cout << "PORTS: " << endl;
			for(int i = 0; i < 25; i++){
				cout << "Port Number: " << Ports[i] << endl;
			}
			cout << "PROTOCOLS: " << endl;
			for(int i = 0; i < 6; i++){
				cout << Protocols[i] << endl;
			}
			cout << endl << endl;
		}
		
		if(securityLevel == "Low"){
			cout << "Traffic Allowed from the following: " << endl;
			cout << "PORTS: " << endl;
			for(int i = 0; i < 30; i++){
				cout << "Port Number: " << Ports[i] << endl;
			}
			cout << "PROTOCOLS: " << endl;
			for(int i = 0; i < 8; i++){
				cout << Protocols[i] << endl;
			}
			cout << endl << endl;
		}
	}
};

int main(){
	cout << "Syed Huzaifa Ali" << endl << "23K-0004" << endl;
	FirewallTool firewall1("High", 2000, 10);
	firewall1.generatelist(4);
	firewall1.performScan();
	
	FirewallTool firewall2("Medium", 1000, 10); 
	firewall2.generatelist(4);
	firewall2.performScan();
	
	FirewallTool firewall3("Low", 1000, 10); 
	firewall3.generatelist(4);
	firewall3.performScan();
	
}
