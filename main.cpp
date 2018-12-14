#include <iostream>
#include <vector>

using namespace std;					//Blueshifty GitHub

//Sums the all laps winning prob and prints all.
float lap_avg(vector<float> x){
	float total = 0;
	for(int i = 0;i <x.size();++i){	
		printf("\nStarter's Winning Probability On %d. Pull = %.8f",i+1,x.at(i));
		total += x.at(i);
	}
	return total;
}


//Calculates the matrix of winning and calculates the winning prob of starter from matrix.
void fonk(float red,float green){
	float prob_matrix[int(red)+1][int(green)+1];
	for(int i=0;i<=red;++i){
		for(int j=0;j<=green;++j){
			if(i==0||j==0){ prob_matrix[i][j] = 1;}
			else{prob_matrix[i][j] = float(i)/(float(i)+float(j));}
		}
	}
	cout<<"\n Probability of Winning Matrix:"<<endl;
	for(int i =0;i<red+1;++i){
		cout<<endl;
		for(int j = 0;j<green+1;++j){
			printf("%.2f\t",prob_matrix[i][j]);
		}
	}

	vector<float> lap_probs; // All probabilities are saved in this vector
	float lap_prob=1; 
	for(int i = 0;i<=int(green);i=i+2){
		for(int j = 0; j<i;++j){
			lap_prob = lap_prob*(1-prob_matrix[int(red)][(int(green)-j)]);
		}
		lap_prob = lap_prob*prob_matrix[int(red)][(int(green)-i)];
		lap_probs.push_back(lap_prob);
		lap_prob = 1;
	}
	float win_total = lap_avg(lap_probs);
	printf("\nWinning Probabality of Starter = %.3f",win_total);
}

int main() {
	float red_marble,green_marble;
	cout<<"*****************************************"<<endl;
	cout<<"Marble Bag Problem With Dynamic Approach"<<endl;
	cout<<"Bag Has 2 Kind of Marbles: Green and Red"<<endl;
	cout<<"2 Players Start to Pull the Marbles From Bag, One by One!"<<endl;
	cout<<"Who Pulls the Red Marble First, Gonna Win!"<<endl;
	cout<<"When There are Only Red Marbles On The Bag, Starter Wins!"<<endl;
	cout<<"Program Will Calculate the Winning Probability of Starter"<<endl;
	cout<<"*****************************************"<<endl;
	cout<<"Enter The Number of Reb Marbles:"<<endl;
	cin>>red_marble;
	cout<<"Enter The Number of Green Marbles:"<<endl;
	cin>>green_marble;
	fonk(red_marble,green_marble);
	return 0;
}
