#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
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
                std::string taskDueDate;
                bool complete;
                int taskId;
                Task(std::string task, std::string dueDate, int id){
                    taskDescription = task;
                    taskDueDate = dueDate;
                    complete = false;
                    taskId = id;
                }
        };

        std::vector<Task> tasks;
        
        void addTask(std::string task, std::string dueDate) {
            Task newTask(task, dueDate, idIncrement);
            idIncrement += 1;
            tasks.push_back(newTask);
        }

        void viewTasks(){
            if (!tasks.empty()){
                for (int i=0;i < tasks.size(); i++){
                    std::cout << "Task Description:"  << tasks[i].taskDescription <<std::endl << "Due Date: " << tasks[i].taskDueDate << std::endl << "ID: " << tasks[i].taskId << std::endl << "Status: " << std::boolalpha << tasks[i].complete << std::endl << " " << std::endl ;
                }
            }else{
                std::cerr << "There are no tasks to display";
            }
            std::cout << "--------------------------------------------------" << std::endl;
        }
        void deleteById(int id){
            for (int i = 0; i < tasks.size(); i++){
                    if (tasks[i].taskId == id){
                        tasks.erase(tasks.begin() + i);
                        break;
                    } 
                }
            }
        void completeTaskById(int id){
            for (int i = 0; i < tasks.size(); i++){
                if(tasks[i].taskId == id){
                    tasks[i].complete = true;
                }
            }
        }
        void editTaskById(std::string task, int id){
            for (int i = 0; i < tasks.size(); i++){
                if(tasks[i].taskId == id){
                    tasks[i].taskDescription = task;
                }
            }
        }


};


int main(){ 
    todoList todoList1;
    todoList1.addTask("Task 1", "1/12");
    todoList1.addTask("Task 2", "1/13");
    todoList1.viewTasks();
    todoList1.completeTaskById(1);
    todoList1.viewTasks();
    todoList1.editTaskById("Task 3", 0);
    todoList1.viewTasks();
}
