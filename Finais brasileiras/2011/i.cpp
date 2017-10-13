#include <bits/stdc++.h>
using namespace std;

int main() {
	int d;
	char c;
	string input;
	string input2[110];
	
	string braile[2][10] = {
		{".*", "*.", "*.", "**", "**", "*.", "**", "**", "*.", ".*"},
		{"**", "..", "*.", "..", ".*", ".*", "*.", "**", "**", "*."}
	};
	
	while(scanf("%d", &d), d) {
		scanf(" %c", &c);
		
		if(c == 'S') {
			cin >> input;
			
			for(unsigned int i = 0; i < 2; i++) {
				cout << braile[i][input[0] - '0'];
				
				for(unsigned int j = 1; j < input.size(); j++)
					cout << " " << braile[i][input[j] - '0'];
				puts("");
			}
			
			printf("..");
			for(unsigned int i = 1; i < input.size(); i++)
				cout << " ..";
			puts("");	
		}
		else {
			for(unsigned int i = 0; i < d; i++)
				cin >> input2[i];
			
			for(unsigned int i = 0; i < d; i++) {
				cin >> input;
				
				if(input == "**") {
					if(input2[i] == ".*")
						cout << '0';
					else if(input2[i] == "**")
						cout << '7';
					else if(input2[i] == "*.")
						cout << '8';
				}
				else if(input == "..") {
					if(input2[i] == "*.")
						cout << '1';
					else if(input2[i] == "**")
						cout << '3';
				}
				else if(input == "*.") {
					if(input2[i] == "*.")
						cout << '2';
					else if(input2[i] == "**")
						cout << '6';
					else if(input2[i] == ".*")
						cout << '9';
				}
				else if(input == ".*") {
					if(input2[i] == "**")
						cout << '4';
					else if(input2[i] == "*.")
						cout << '5';
				}
			}
			
			for(unsigned int i = 0; i < d; i++)
				cin >> input;
			
			puts("");
		}
	}
}
