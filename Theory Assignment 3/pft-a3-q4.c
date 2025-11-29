#include <stdio.h>
#include <string.h>

struct Shelf {
 int bookId[25];
 int popScore[25];
 int count;
};

//x = bookID, y = popscore
void add(struct Shelf *s, int x, int y){
   //if x == s.bookId[i] THEN s.popscore[i] = y
   //if count == 24 THEN s.bookid[i] = s.bookid[i+1]
   //s.popscore[i] = s.popscore[i+1]
   //s.bookid[24] = x
   //s.popscore = y;
   //ELSE s.bookId[count] = x
   //s.popscore[count] = y;
   //count++
    
   for(int i = 0; i < s->count; i++){
   
    if(x == s->bookId[i]){
        s->popScore[i] = y;
        

      int tempId = s->bookId[i];
      int tempScore = s->popScore[i];
      for(int j = i; j< s->count-1;j++){
        s->bookId[j] = s->bookId[j+1];
        s->popScore[j] = s->popScore[j+1];
      }

      s->bookId[s->count-1] = tempId;
      s->popScore[s->count-1] = tempScore;
       
      return;
    }
}

    if(s->count==24){
        for(int i = 0; i < 23;i++){
            s->bookId[i] = s->bookId[i+1];
            s->popScore[i] = s->popScore[i+1];
        }

        s->bookId[23] = x;
        s->popScore[23] = y;
        s->count++;
    }
}
        


  
   


//x = bookID
int access(struct Shelf *s, int x){
  
  for(int i =0; i < 25;i++){
    if(x==s->bookId[i]){
        int score =  s->popScore[i];
        
        int tempId = s->bookId[i];
        int tempScore = s->popScore[i];
        for(int j=i; j< s->count-1;j++){
            s->bookId[j] = s->bookId[j+1];
            s->popScore[j] = s->popScore[j+1];

        }
        s->bookId[s->count - 1] = tempId;
        s->popScore[s->count-1] = tempScore;

        return score;
    }
}

    return -1;
        
    }


 


int main(){

int capacity, Q;
    scanf("%d %d", &capacity, &Q);
    
    struct Shelf s;
    s.count = 0;


for(int i = 0; i < Q; i++){
        char operation[10];
        scanf("%s", operation);
        if(strcmp(operation, "ADD") == 0){
    int x, y;
    scanf("%d %d", &x, &y);
    add(&s, x, y);
} else {
    int x;
    scanf("%d", &x);
    printf("%d\n", access(&s, x));
}
}


return 0;
}