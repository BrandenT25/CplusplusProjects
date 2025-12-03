#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>






class TodoList{
    public:
        int idIncrement;
        std::unordered_map<int, size_t> idToIndex;
        void todoList(){
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
            size_t index = idToIndex[id];
            tasks[index].taskDescription = task;
        }
        


};


TodoList initList(){
  TodoList todoList;
  return(todoList);
}
  
void userInputHandler(){
  while(true){
    int input;

    std::cout << "==========================" << std::endl << "         Todo List         " << std::endl << "==========================" << std::endl << "1. | View Tasks" << std::endl << "2. | Edit Task" << std::endl << "3. | Complete Task" << std::endl << "4. | Delete Task" << std::endl << "5. | Save & Exit" << std::endl << std::endl <<  "--------------------------" << std::endl;
    std::cin >> input;
    switch(input){
      case 1:
        std::cout << "view function";
        break;
      case 2:
        std::cout << "edit function";
        break;
      case 3:
        std::cout << "complete function";
        break;
      case 4:
        std::cout << "delete function";
        break;
      case 5:
        std::cout << "save function";
        break;



    }    
  }
}


int main(){ 
    TodoList todoList1 = initList();
    userInputHandler();
    todoList1.addTask("Task 1", "1/12");
    todoList1.addTask("Task 2", "1/13");
}
