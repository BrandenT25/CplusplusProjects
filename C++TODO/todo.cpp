#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
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
        std::unordered_map<int, size_t> idToIndex;
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
            size_t index = tasks.size();
            tasks.push_back(newTask);
            idToIndex[idIncrement] = index;
            idIncrement += 1;
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
          size_t index = idToIndex[id];
          size_t lastIndex = tasks.size() - 1;
          int swapId = tasks[lastIndex].taskId;
          idToIndex[swapId] = index;
          std::swap(tasks[index], tasks[lastIndex]);
          tasks.pop_back();
          idToIndex.erase(id);
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
    todoList1.deleteById(0);
    todoList1.viewTasks();
    todoList1.addTask("Do something", "1/5");
    todoList1.addTask("Do something again", "1/6");
    todoList1.viewTasks();
    todoList1.deleteById(2);
    todoList1.viewTasks();
}
