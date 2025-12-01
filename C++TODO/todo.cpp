#include <iostream>
#include <fstream>
#include <string>
int main(){
  
  std::ofstream outputFile("text.txt");


  if (outputFile.is_open()){
    outputFile << "First Line" << std::endl;
    outputFile << "Second Line" << std::endl;

    outputFile.close();

  }else{
    std::cerr << "Error Opening File" << std::endl;


  }
  return 0;

}

class Task{
  private:
    string Task;
    bool complete;  
    string dueDate;
    Task(string Task, ){
    


    }


}
