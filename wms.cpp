#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string>
using namespace std;
struct item{
    string name,id,type1,type2;
    int toxic,env;
};
item e[100];
int total=0;
void itemdata(){
    int choice;
    cout<<"How many waste item do you want to enter??: ";
    cin>>choice;
    for(int i=total;i<total+choice;i++){
        cout<<"Enter data of item"<<i+1<<endl;
        cout<<"Item Name: ";
        cin>>e[i].name;
        cout<<"Item ID: ";
        cin>>e[i].id;
        cout<<"Type 1(B for Biodegradable/ NB for Non-Biodegradable): ";
        cin>>e[i].type1;
        cout<<"Type 2(D for Dry/ W for Wet): ";
        cin>>e[i].type2;
        cout<<"Toxic level(out of 10): ";
        cin>>e[i].toxic;
        cout<<"Enviromental Damage(out of 100): ";
        cin>>e[i].env;
    }
    total=total+choice;
}
void show(){
    if(total!=0){
        for(int i=0;i<total;i++){
            cout<<"Data of item "<<i+1<<endl;
            cout<<"Item Name: "<<e[i].name<<endl;
            cout<<"Item ID: "<<e[i].id<<endl;
            cout<<"Type 1: "<<e[i].type1<<endl;
            cout<<"Type 2: "<<e[i].type2<<endl;
            cout<<"Toxic Level: "<<e[i].toxic<<endl;
            cout<<"Enviromental Damage: "<<e[i].env<<endl;
        }
    }
    else{
        cout<<"Your slot is empty"<<endl;
    }
}
void search(){
    if(total!=0){
        string id;
        cout<<"Enter id of item which you want to search: "<<endl;
        cin>>id;
        for(int i=0;i<total;i++){
            if(id==e[i].id){
                cout<<"Data of item "<<i+1<<endl;
                cout<<"Item Name: "<<e[i].name<<endl;
                cout<<"Item ID: "<<e[i].id<<endl;
                cout<<"Type 1: "<<e[i].type1<<endl;
                cout<<"Type 2: "<<e[i].type2<<endl;
                cout<<"Toxic Level: "<<e[i].toxic<<endl;
                cout<<"Enviromental Damage: "<<e[i].env<<endl;
                break;
            }
            if(i==total-1){
                cout<<"No such item found"<<endl;
            }
        }
        
    }
    else{
        cout<<"Your slot is empty"<<endl;
    }
}
void update(){
    if(total!=0){
        string id;
        cout<<"Enter id of item which you want to update: "<<endl;
        cin>>id;
        for(int i=0;i<total;i++){
            if(id==e[i].id){
                cout<<"Previous Data"<<endl;
                cout<<"Data of Item "<<i+1<<endl;
                cout<<"Item Name: "<<e[i].name<<endl;
                cout<<"Item ID: "<<e[i].id<<endl;
                cout<<"Type 1: "<<e[i].type1<<endl;
                cout<<"Type 2: "<<e[i].type2<<endl;
                cout<<"Toxic Level: "<<e[i].toxic<<endl;
                cout<<"Enviromental Damage: "<<e[i].env<<endl;
                cout<<"\n Enter new data"<<endl;
                cout<<"Item Name: ";
                cin>>e[i].name;
                cout<<"Item ID: ";
                cin>>e[i].id;
                cout<<"Type 1: ";
                cin>>e[i].type1;
                cout<<"Type 2: ";
                cin>>e[i].type2;
                cout<<"Toxic Level: ";
                cin>>e[i].toxic;
                cout<<"Enviromental Damage: ";
                cin>>e[i].env;
                break;
            }
            if(i==total-1){
                cout<<"No such item found"<<endl;
            }
        }

    }
    else{
        cout<<"Your slot is empty"<<endl;
    }
}
void disp(){
    if(total!=0){
        char user;
        cout<<"Press 1 to dispose all items"<<endl;
        cout<<"Press 2 to dispose specific item"<<endl;
        user=getch();
        if(user=='1'){
            total=0;
            cout<<"All items are disposed...!!!"<<endl;
        }
        else if(user=='2'){
            string id;
            cout<<"Enter id of item which you want to dispose: "<<endl;
            cin>>id;
            for(int i=0;i<total;i++){
                if(id==e[i].id){
                    for(int j=i;j<total;j++){
                        e[j].name=e[j+1].name;
                        e[j].id=e[j+1].id;
                        e[j].type1=e[j+1].type1;
                        e[j].type2=e[j+1].type2;
                        e[j].toxic=e[j+1].toxic;
                        e[j].env=e[j+1].env;
                        total--;
                        break;
                    }
                }
                if(i==total-1){
                    cout<<"No such item found"<<endl;
                }
            }
        }
    }
    else{
        cout<<"Your slot is empty"<<endl;
    }
}
int main(){
    cout<<"\n\n\t\tSmart Waste Management System - Devashish Bisht"<<endl;
    cout<<"\n\n\t\tSign Up"<<endl;
    string username,password;
    cout<<"\n\t\tEnter username: ";
    cin>>username;
    cout<<"\n\t\tEnter password: ";
    cin>>password;
    cout<<"\n\t\tYour id is creating please wait....";
    for(int i=0;i<4;i++){
        cout<<".";
        Sleep(1000);
    }
    cout<<"\n\t\tYour id is created successfully"<<endl;
    system("CLS");
    start:

    cout<<"\n\n\t\tSmart Waste Management System - Devashish Bisht"<<endl;
    cout<<"\n\n\t\tLogin"<<endl;
    string username1,password1;
    cout<<"\n\t\tUsername: ";
    cin>>username1;
    cout<<"\n\t\tPassword: ";
    cin>>password1;
    cout<<"\n\t\tYour id is logging please wait....";
    for(int i=0;i<4;i++){
        cout<<".";
        Sleep(1000);
    }
    if(username1==username&&password1==password){
        system("CLS");
        char user;
        while(1){
            cout<<"\nPress 1 to enter item"<<endl;
            cout<<"Press 2 to show item"<<endl;
            cout<<"Press 3 to search item"<<endl;
            cout<<"Press 4 to update item"<<endl;
            cout<<"Press 5 to dispose item"<<endl;
            cout<<"Press 6 to logout"<<endl;
            user=getch();
            switch(user){
                case '1':
                    itemdata();
                    break;
                case '2':
                    show();
                    break;
                case '3':   
                    search();
                    break;
                case '4':
                    update();
                    break;
                case '5':
                    disp();
                    break;
                case '6':
                    goto start;
                    break;
                default:
                    cout<<"\aInavlid input"<<endl;
                    break;                        
            }
        }
    }
    else if(username!=username){
        cout<<"Your username is incorrect"<<endl;
        Sleep(3000);
        goto start;
    }
    else if(password1!=password){
        cout<<"Your passowrd is incorrect"<<endl;
        Sleep(3000);
        goto start;
    }
    return 0;
}
//DevashishBisht