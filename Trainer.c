#include <windows.h>
#include <iostream>
#include <wchar.h>
#include <TlHelp32.h>

using namespace std;

int ProcessId(){
	
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnapshot) {
		PROCESSENTRY32 processes;
		processes.dwSize = sizeof(PROCESSENTRY32);
		Process32First(hSnapshot,&processes);
		do{
			if(wcscmp(processes.szExeFile,L"HackSlashLoot.exe") == 0) return processes.th32ProcessID ;
			}while(Process32Next(hSnapshot,&processes));
	
	}
	cout << "\n[~] Game is not started yet ,run the trainer after the game is started\n";
	CloseHandle(hSnapshot);
	exit(1);
	return 1 ;

}

int VirtualAddress(){
 HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, ProcessId());
	if (hSnapshot) {
		MODULEENTRY32 Module;
		Module.dwSize = sizeof(MODULEENTRY32);
		Module32First(hSnapshot,&Module);
		do{
			if(wcscmp(Module.szModule,L"HackSlashLoot.exe") == 0) {
				return (int)(Module.modBaseAddr+0x7a6140);
			}
			}while(Module32Next(hSnapshot,&Module));
	
	}

	cout << "\n[~] Game has been closed ,restart it \n";
	CloseHandle(hSnapshot);
	exit(1);
	return 1 ;
}

int main(){


//  ████████╗██████╗  █████╗ ██╗███╗   ██╗███████╗██████╗     ██████╗ ██╗   ██╗    ██████╗ ██████╗ ███████╗ █████╗  ██╗████████╗
//  ╚══██╔══╝██╔══██╗██╔══██╗██║████╗  ██║██╔════╝██╔══██╗    ██╔══██╗╚██╗ ██╔╝    ██╔══██╗╚════██╗██╔════╝██╔══██╗███║╚══██╔══╝
//     ██║   ██████╔╝███████║██║██╔██╗ ██║█████╗  ██████╔╝    ██████╔╝ ╚████╔╝     ██║  ██║ █████╔╝█████╗  ███████║╚██║   ██║   
//     ██║   ██╔══██╗██╔══██║██║██║╚██╗██║██╔══╝  ██╔══██╗    ██╔══██╗  ╚██╔╝      ██║  ██║ ╚═══██╗██╔══╝  ██╔══██║ ██║   ██║   
//     ██║   ██║  ██║██║  ██║██║██║ ╚████║███████╗██║  ██║    ██████╔╝   ██║       ██████╔╝██████╔╝██║     ██║  ██║ ██║   ██║   
//     ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝    ╚═════╝    ╚═╝       ╚═════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝ ╚═╝   ╚═╝   
//   
 
 

cout<<" /$$$$$$$$              /$$\n";                          
cout<<"|__  $$__/             |__/\n";                      
cout<<"   | $$ /$$$$$$ /$$$$$$ /$$/$$$$$$$  /$$$$$$  /$$$$$$\n";
cout<<"   | $$/$$__  $|____  $| $| $$__  $$/$$__  $$/$$__  $$\n";
cout<<"   | $| $$  \\__//$$$$$$| $| $$  \\ $| $$$$$$$| $$  \\__/ \n";
cout<<"   | $| $$     /$$__  $| $| $$  | $| $$_____| $$\n";
cout<<"   | $| $$    |  $$$$$$| $| $$  | $|  $$$$$$| $$\n";
cout<<"   |__|__/     \\_______|__|__/  |__/\\_______|__/\n";
                                                      
                                                      




cout<<" /$$                      /$$$$$$$  /$$$$$$  /$$$$$$          /$$  /$$\n";    
cout<<"| $$                     | $$__  $$/$$__  $$/$$__  $$       /$$$$ | $$\n";    
cout<<"| $$$$$$$ /$$   /$$      | $$  \\ $|__/  \\ $| $$  \\__/$$$$$$|_  $$/$$$$$$\n";  
cout<<"| $$__  $| $$  | $$      | $$  | $$  /$$$$$| $$$$  |____  $$ | $|_  $$_/\n";  
cout<<"| $$  \\ $| $$  | $$      | $$  | $$ |___  $| $$_/   /$$$$$$$ | $$ | $$\n";    
cout<<"| $$  | $| $$  | $$      | $$  | $$/$$  \\ $| $$    /$$__  $$ | $$ | $$ /$$\n";
cout<<"| $$$$$$$|  $$$$$$$      | $$$$$$$|  $$$$$$| $$   |  $$$$$$$/$$$$$|  $$$$/\n";
cout<<"|_______/ \\____  $$      |_______/ \\______/|__/    \\_______|______/\\___/\n";  
cout<<"          /$$  | $$\n";                                                       
cout<<"         |  $$$$$$/\n";                                                       
cout<<"          \\______/\n";                                                        


                                                      
                                                      
                                                      

 cout << "\n\n[~] Finding the ProcessId of the game to inject our code ";
 int pid = ProcessId();
 cout << "\n[~] ProcessID of the game is "<<pid;
 cout << "\n[~] Hooking into our process ";
 cout << "\n[~] Enjoy max Health ,Armour ,Attacks :) ";

 int ptr,health,nhealth;
 int max = 999 , pmax = 100 , dmax = 991;
 HANDLE game = OpenProcess(PROCESS_VM_OPERATION|PROCESS_VM_READ|PROCESS_VM_WRITE,FALSE,pid);
 if(game)
	if(ReadProcessMemory(game,(void *)VirtualAddress(),&ptr,4,NULL))
		if(ReadProcessMemory(game,(void *)(ptr+0x50),&health,4,NULL))
			while(1){
			WriteProcessMemory(game,(void *)(ptr+0x34),&pmax,4,NULL); // Melee  Attack %
			WriteProcessMemory(game,(void *)(ptr+0x38),&pmax,4,NULL); // Ranged Attack %
			WriteProcessMemory(game,(void *)(ptr+0x3c),&pmax,4,NULL); // Magic  Attack %
			WriteProcessMemory(game,(void *)(ptr+0x40),&max,4,NULL);  // Melee  Damage
			WriteProcessMemory(game,(void *)(ptr+0x44),&max,4,NULL);  // Ranged Damage 
			WriteProcessMemory(game,(void *)(ptr+0x48),&max,4,NULL);  // Armour
			WriteProcessMemory(game,(void *)(ptr+0x4c),&dmax,4,NULL); // Magic Damage
			WriteProcessMemory(game,(void *)(ptr+0x50),&max,4,NULL);  // Health
				}
return 0 ;
}
