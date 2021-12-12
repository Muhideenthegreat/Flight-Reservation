#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class passengers{
  private:
    string name;
    string firstname;
    string lastname;
    int ticketNo;
    int price;
    int seatNo;
    int Stype;
    int bsize;
    int esize;

  public:
  passengers(string firstname,string lastname,int ticketNo,int price, int seatNo,int Stype){
    (*this).firstname=firstname;
    (*this).lastname=lastname;
    (*this).ticketNo=ticketNo;
    (*this).price=price;
    (*this).seatNo=seatNo;
    (*this).Stype=Stype;
  }
  passengers(){
  }

  void setticketNo(int ticketNo){
    (*this).ticketNo=ticketNo;
  }
  void setprice(int price){
    (*this).price=price;
  }
  void setfirstname(string firstname){
    (*this).firstname=firstname;
  }  
  void setlastname(string lastname){
    (*this).lastname=lastname;
  } 
  void setStype(int Stype){
    (*this).Stype=Stype;
  }
  void setseatNo(int seatNo){
    (*this).seatNo=seatNo;
  }
  
  int getticketNo(){
    return ticketNo;
  }
  int getprice(){
    return price;
  }
  int getseatNo(){
    return seatNo;
  }
  int getStype(){
    return Stype;
  }
  string getlastname(){
    return lastname;
  }
  string getfirstname(){
    return firstname;
  }

  void getData(){
      cout<<"Enter first name: ";
      cin>>firstname;
      cout<<"Enter last name: ";
      cin>>lastname;
      cout<<endl;   

  
      cout<<"Pick a class "<<endl<<"1. Business class"<<endl<<"2. Economy class"<<endl;
      cin>>Stype;
      if(Stype==1){
        price=100;
        cout<<"The ticket price = $ "<<price<<endl;
        cout<<"Seats Available: ";
        for(int i=1;i<=5;i++){
          cout<<i<<" ";
          }
          cout<<endl<<"What seat number would you like to book? ";
          cin>>seatNo;
          
      }else if(Stype==2){
        price=75;
        cout<<"The ticket price = $ "<<price<<endl;
        cout<<"Seats Available: ";
        for(int i=1;i<=7;i++){
          cout<<i<<" ";
          ;}
          cout<<endl<<"What seat number would you like to book? ";
          cin>>seatNo;
      }
  
      ticketNo=10000+seatNo;
      cout<<"TicketNo: "<<ticketNo<<endl;  
    }
  
};

class flight{
  private:
    string planeId;
    string flightNo;
    passengers *Economy;
    passengers *Business;
    int *seatseconomy;
    int *seatsbusiness;
    int bsize;
    int esize;
    string fromLocation;
    string toLocation;
    string arrivalDate;
    string leaveDate;
    int cEseat=0;
    int cBseat=0;
   // passengers *flight1;

  public: 
    flight(string planeId,string flightNo,string arrivalDate,string leaveDate, string fromLocation, string toLocation, int bsize, int esize){
      (*this).planeId=planeId;
      (*this).flightNo=flightNo;
      (*this).arrivalDate=arrivalDate;
      (*this).leaveDate=leaveDate;
      (*this).fromLocation=fromLocation;
      (*this).toLocation=toLocation;
      (*this).bsize=bsize;
      (*this).esize=esize;
      Economy=new passengers[esize];
      Business=new passengers[bsize];

      seatseconomy = new int[esize];
      for (int i = 0; i<esize; i++) {
      seatseconomy[i] = i + 1;
      }

      seatsbusiness = new int[bsize];
      for (int i = 0; i<bsize; i++) {
      seatsbusiness[i] = i + 1;
      }
    }

    void setbsize(int bsize){
      (*this).bsize=bsize;
    }
    void setplaneId(string planeId){
      (*this).planeId=planeId;
    }
    void setflightNo(string flightNo){
      (*this).flightNo=flightNo;
    }
    void setleaveDate(string leaveDate){
      (*this).leaveDate=leaveDate;
    }
    void setarrivalDate(string arrivalDate){
      (*this).arrivalDate=arrivalDate;
    }

    int getbsize(){
      return bsize;
    }
    string getflightNo(){
      return flightNo;
    }
    string getarrivalDate(){
      return arrivalDate;
    }
    string getleaveDate(){
      return leaveDate;
    }
    string getplaneId(){
      return planeId;
    }
    string getfromLocation(){
      return fromLocation;
    }
    string gettoLocation(){
      return toLocation;
    }

    void add(passengers p){
      
      if(p.getStype()==1){
          Business[cBseat]=p;
          cBseat++;
      }else if(p.getStype()==2){
          Economy[cEseat]=p;
          cEseat++;
      }
    }

    void remove(passengers p){
      int i;
      for(i=0;i<cEseat;i++){
        if(p.getStype()==1){
          for(int j=i;j<cEseat;j++){
            Business[j].setStype(Business[j+1].getStype());
          }
          cEseat--;
          break;
        }
      }
    }

    void displayFlight(){
      cout<<"-------------- "<<getplaneId()<<" DataBase"<<"--------------"<<endl;
      cout<<"Flight Number: "<<getflightNo()<<endl;
      cout<<"Destination:"<<getfromLocation()<<" "<<"to"<<"  "<<gettoLocation()<<endl;
      cout<<"Leave Date: "<<getleaveDate()<<endl; cout<<"Arrival Date: " <<getarrivalDate()<<endl;
      cout<<"Business Class: "<<endl;
      for(int i=0;i<bsize;i++){
        cout<<Business[i].getfirstname()<< " "<<Business[i].getlastname()<<" "<<Business[i].getticketNo()<<endl;
      }
      cout<<"Economy Class: "<<endl;
      for(int i=0;i<esize;i++){
        cout<<Economy[i].getfirstname()<< " "<<Economy[i].getlastname()<<" "<<Economy[i].getticketNo()<<endl;
      }

    }

    void open(string fileName){
      ofstream fout;
      fout.open(fileName, ios::out);

      fout<<"FirstName"<<setw(10)<<"LastName"<<setw(10)<<"SeatNo"<<setw(10)<<"Price"<<setw(10)<<"TicketNo"<<endl;
      fout<<"Business Class: "<<endl;
        for(int i=0;i<cBseat;i++){
        fout<<Business[i].getfirstname()<<setw(10)<<Business[i].getlastname()<<setw(10)<<Business[i].getseatNo()<<setw(10)<<Business[i].getprice()<<setw(10)<<Business[i].getticketNo();
        }

      fout<<endl;
      
      fout<<"Economy Class: "<<endl;
        for(int i=0;i<cEseat;i++){
        fout<<Economy[i].getfirstname()<<setw(10)<<Economy[i].getlastname()<<setw(10)<<Economy[i].getseatNo()<<setw(10)<<Economy[i].getprice()<<setw(10)<<Economy[i].getticketNo();
        }

      cout << "...Saved\n";
    
    fout.close();
    }

};

flight f1("Arik Airways","A370","08/02/21","08/01/21","Paris","Germany",5,7);
flight f2("Fly Emirates","A370","18/02/21","16/01/21","Nigeria","Italy",5,7);
flight f3("American Airlines","A370","14/02/21","15/02/21","CostaRica","Spain",5,7);

int main(){
  passengers p;
  passengers p1;
  passengers p2;

  bool done = false;
  while (!done) {
  int option,info;
  int choice;
  int num;
  cout<<"============================================="<<endl;
  cout<<"***"<<" Welcome to Mustapha's Airline Reservation"<<" ***"<<endl;
  cout<<"1.Book a flight"<<endl<<"2.Cancel a reservation"<<endl<<"3.Display Flight Information"<<endl<<"4.Exit"<<endl;
    cin>>option;
  cout<<"============================================="<<endl;


    switch(option){
    case 1: 
      cout<<"Enter Passenger's Information:  "<<endl;
      p.getData();
      cout<<"============================================="<<endl;
      cout<<"Pick an Airline: "<<endl;
        cout<<"1. Arik Airlines"<<endl<<"Destination:"
        <<f1.getfromLocation()<<" "<<"to"<<"  "<<f1.gettoLocation()<<endl<<f1.getleaveDate()<<" - "<<f1.getarrivalDate()<<endl;
        cout<<"2. Fly Emirates"<<endl
          <<"Destination: "
          <<f2.getfromLocation()<<" "<<"to"<<"  "<<f2.gettoLocation()<<endl
          <<f2.getleaveDate()<<" - "<<f2.getarrivalDate()<<endl;
        cout<<"3. American Airlines"<<endl
          <<"Destination: "
          <<f3.getfromLocation()<<" "<<"to"<<"  "<<f3.gettoLocation()<<endl
          <<f3.getleaveDate()<<" - "<<f1.getarrivalDate()<<endl;
      cin>>choice;
      cout<<"============================================="<<endl;

      if(choice==1){
        f1.add(p);
        f1.open("Arik Airways");
      }else if(choice==2){
        f2.add(p);
        f2.open("Fly Emirates");
      }else if(choice==3){
        f3.add(p);
        f3.open("American Airline");
      }
    break;

    //case 2:
    cout<<"Enter Passenger's Information:  "<<endl;
      p.getData();
      cout<<"============================================="<<endl;
      cout<<"What Reservation are you cancelling? "<<endl;
        cout<<"1. Arik Airlines"<<endl<<"Destination:"
        <<f1.getfromLocation()<<" "<<"to"<<"  "<<f1.gettoLocation()<<endl<<f1.getleaveDate()<<" - "<<f1.getarrivalDate()<<endl;
        cout<<"2. Fly Emirates"<<endl
          <<"Destination: "
          <<f2.getfromLocation()<<" "<<"to"<<"  "<<f2.gettoLocation()<<endl
          <<f2.getleaveDate()<<" - "<<f2.getarrivalDate()<<endl;
        cout<<"3. American Airlines"<<endl
          <<"Destination: "
          <<f3.getfromLocation()<<" "<<"to"<<"  "<<f3.gettoLocation()<<endl
          <<f3.getleaveDate()<<" - "<<f1.getarrivalDate()<<endl;
      cin>>choice;

      if(choice==1){
        f1.remove(p);
        f1.open("Arik Airways");
      }else if(choice==2){
        f2.remove(p);
        f2.open("Fly Emirates");
      }else if(choice==3){
        f3.remove(p);
        f3.open("Qatar Airways");
      }
      break;

    case 3:
      cout<<"Which flight information are you interested in?"<<endl<<"1. Arik Airways"<<endl<<"2. Fly Emirates"<<endl<<"3. Qatar Airways"<<endl;
      cin>>info;
      cout<<"============================================="<<endl;

      if(info==1){
        f1.displayFlight();
      }else if(info==2){
        f2.displayFlight();
      }else if(info==3){
        f3.displayFlight();
      }

    case 4:
     done=true;
  }
  }
}

   

  