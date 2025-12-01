#include <iostream>
#include <fstream>
#include <string>
#include <vector>
/*
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
 */









class todoList{
    public:
        int idIncrement;
        todoList(){
            idIncrement = 0;
        }
        class Task{
            public:
                std::string taskDescription;
                std::string dueDate;
                bool complete;
                int id;
                Task(std::string task, std::string dueDate, int id){
                    taskDescription = task;
                    dueDate = dueDate;
                    complete = false;
                    id = id;
                }
        };
        std::vector<Task> tasks;
        
        void addTask(std::string task, std::string dueDate) {
            Task newTask(task, dueDate, idIncrement);
            idIncrement += 1;
            tasks.push_back(newTask);
        }
};


int main(){ 
    todoList todoList1;
    todoList1.addTask("Hellodsas", "1/12");
    if (!todoList1.tasks.empty()){
        std::cout << "first Task: " << todoList1.tasks[0].id;
    }else{
        std::cout << "there are not tasks";
    }
}
