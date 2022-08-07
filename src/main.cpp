#include <iostream>
#include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
using namespace std;

int main() {	//Taking input in parent process and calculating factorial in child process
    
	pid_t pID;
	int val;
	
	cout << "Enter a Number: ";
	cin >> val;
	
	pID = fork();

	if (pID > 0) {
		//parent code

		cout << "Parent Process: " << endl;
		cout << "	My ID= " << getpid() <<", My PPID= " << getppid() << ", My Child's ID= " << pID << endl;

	} else if (pID == 0) {
		//child code

		 cout << "Child Process: " << endl;
		 cout << "	My ID= " << getpid() <<", My PPID= " << getppid() << ", My Child's ID= " << pID << endl;
	 
		int a = 1;
		for (int i = 1; i <= val; i++){
			a *= i;
		}

		cout << "Factorial= ";
		cout << a << endl;

	} else {
		//fork error
		cout << "Fork failed" << endl;

	}

    return 0;
}

int main0() {	//taking input in child process and calculating facrotial in parent process
    
	pid_t pID;
	int val;
	int status;
	
	pID = fork();

	if (pID > 0) {
		//parent code
		
		wait(&status);	//Parent process waits until any one of its children terminates and stores the value returned by exit() in status variable
		status = WEXITSTATUS(status);	//Status returned in a multiple of 256 so divide it by 256 or simply call the function

		cout << "Parent Process: " << endl;

		int a = 1;
		for (int i = 1; i <= status; i++){
			a *= i;
		}

		cout << "	Factorial= ";
		cout << a << endl;
		

	} else if (pID == 0) {
		//child code

		cout << "Child Process: " << endl;

		cout << "	Enter a Number: ";
		cin >> val;

		exit(val); //terminate the child process and return to parent process with a value passed to the perimeter of wait()
		
	} else {
		//fork error
		cout << "Fork failed" << endl;

	}

    return 0;
}


