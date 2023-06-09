#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

class queue
{
public:
	int *antrian;
	int ukuran;
	int top;
	void insertQueue(int i);
	void deleteQueue();
	void find(int i);
	void display();


queue(int i){
		ukuran=i;
		antrian=new int[ukuran];
		top=0;
	}
	
private:
	int isEmpety();
	int isFull();	
};

int queue::isEmpety(){
	if(top<=0)
		return 1;
	else
		return 0;
}


int queue::isFull(){
	if(top>=ukuran)
		return 1;
	else
		return 0;
}

void queue::insertQueue(int i){
	if(isFull()==1){
		cout<<"Maaf Antrian Penuh Gaes"<<endl;
	}else{
        cout<<"Nilai "<<i<<" masuk antrian dulu yaa"<<endl;
        antrian[top++]=i;
	}
}

void queue::deleteQueue(){
	if(isEmpety()==1){
		cout<<"Sory gaes udah kosong nih"<<endl;
	}else{
		int pop=antrian[0];
		int i=1;
		cout<<"Nilai "<<pop<<" keluar antrian"<<endl;
		while(i<top){
			antrian[i-1]=antrian[i];
			i++;
		}
		top--;
	}
}

void queue::find(int i){
    
	int temp=0;
	int hasil=0;
	while(temp<top){
		if(i=antrian[temp]){
			hasil=1;
			break;
		}
		temp++;
	}

	if (hasil==1){
		cout<<"Nilai "<<i<<" ditemukan diantrian ke "<<(temp+1)<<endl;
        
        
	}else{
		cout<<"Antrian tidak ditemukan"<<endl;
        
        
	}

   
}

void queue::display(){
	cout<<"Isi Antrian "<<endl;
	int i=0;
	while(i<top){
		cout<<"Antrian ke ["<<(i+1)<<"]:"<<antrian[i]<<endl;
		i++;
	}
}

int main(int argc, char const *argv[])
{
	int ukuran;
	int pilih;

	cout<<"Program queue/antrian"<<endl;
	cout<<endl;
	cout<<"Masukan jumlah antrian ";
	cin>>ukuran;

	queue * q;
	q=new queue(ukuran);

	do{
      cout<<endl<<endl;
        cout<<"  =============================="<<endl;
        cout<<"  =\t  PROGRAM QUEUE        ="<<endl;
        cout<<"  =============================="<<endl;
        cout<<"  =  1. ENQUEUE                = "<<endl;
        cout<<"  =  2. DEQUEUE                = "<<endl;
        cout<<"  =  3. TAMPIL                 = "<<endl;
        cout<<"  =  4. CLEAR                  = "<<endl;
        cout<<"  =  5. EXIT                   ="<<endl;
      cout<<"  =============================="<<endl;
        cout<<"  Masukan Pilihan : ";cin>>pilih;
        switch(pilih)
        {
                case 1:
				int c;
				cout<<"Masukan bilangan ";
				cin>>c;
                q->insertQueue(c);
				break;
			case 2:
				q->deleteQueue();
				break;
			case 3:
				int k;
				cout<<"Masukan angka yang dicari : ";
				cin>>k;
				q->find(k);
				break;
			case 4:
				q->display();
				break;
          	case 5:
                break;
        }
    } while(pilih!=5);
    	delete q->antrian;
    	return 0;
}