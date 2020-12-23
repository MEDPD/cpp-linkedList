#include <iostream>

using namespace std;


class Point{

    private:
            /* data */
            int x, y;
    public:
        Point(){
            x = 0; y = 0;
        }
        Point(int x, int y){
            this->x = x; this->y = y;
        };

        ~Point(){
            cout << "Point garbage collector" << endl;
        };

};
struct List{
    List(Point p){
        this->data = p;
        this->next = NULL;
    };
    Point data;
    List* next;
};
class LinkedList{

private:

    List* head;
    
public:
    LinkedList(){
        this->head = NULL;
    };
    ~LinkedList(){
        List* tmp = this->head;
        while(this->head){
            tmp = this->head;
            this->head = this->head->next;
            delete tmp;
        }
    }

    List* head(){
        return this->head;
    }
    bool isEmpty(){
       if(!this->head) return false;
       return true;
    };

    List* queue(){
        List* tmp = this->head;
        while (tmp->next) tmp = tmp->next;
        return tmp;
        
    }
    bool push(Point p){
        List* newEl = new List(p);
        if(isEmpty()) this->head = newEl;
        else{
            List* queue = this->queue();
            queue->next = newEl;
        }
        
    };
    bool push(int x, int y){
        this->push(Point(x, y));
    };
    Point* pop(){
        Point* p = NULL;
        List* tmp = this->head;
        while (tmp->next->next) tmp = tmp->next;
        if(isEmpty()) return p;
        else {
            p = new Point(tmp->next->data);
            delete tmp->next;
            tmp->next = NULL;
            return p;
        }
    }


};


Point promptPoint(){
    int x, y; 
    cout << "prompt data "; cin >> x >> y; cout << endl;
    return Point(x, y);
}
int main(int argc, char const *argv[])
{
    bool Quit = true;
    char input;
    Point in;
    LinkedList list = LinkedList();


    while(Quit){
        switch (input)
        {
        case 'p':
            in = promptPoint();
            list.push(in);
            break;
        case 'o':
            
            break;
        
        default:
            break;
        }
    }
    return 0;
}
