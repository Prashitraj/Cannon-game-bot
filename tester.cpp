#include <iostream>
#include <list> 
#include <iterator>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;



int getinteger(string s)
{
  if(s == "1")
  return 1;
  if(s=="2")
  return 2;
  if(s == "3")
  return 3;
  if(s=="4")
  return 4;
  if(s=="5")
  return 5;
  if(s == "6")
  return 6;
  if(s=="7")
  return 7;
  return 0;

}

class Node 
{
    public :
    vector<vector<char> > data;
    bool stalemate;
    Node (int i , int j)
    {
       vector<vector < char > > v (i,vector<char> (j,' ') );
       data = v;
    }
    int set;
   Node * parent = NULL;
   vector<Node *> child;

};

const int MAX = 10000; 
const int MIN = -10000; 

vector<string> split(string w)
{
    vector<string> answer;
    int n = w.length();
    char char_array[n + 1]; 
    strcpy(char_array, w.c_str());
    char * token = strtok(char_array," ");
    
    
    while (token != NULL) 
    { 
        string s (token);
        answer.push_back(s);
        token = strtok(NULL, " "); 
    } 
    
    return answer;
}


void print(vector<vector<char> > v , int r , int c )
{
    for(int i =0 ; i<r ; i++)
    {
        for(int j =0 ; j<c ; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int count (vector<vector<char> > v , int r , int c ,char value)
{
    int c1=0;
    for(int i=0 ; i< r ; i++)
    {
        for(int j=0 ; j< c ; j++)
        {
            if(v[i][j] == value)
            c1++;
        }
    }
    return c1;
}

int isfinal (vector<vector<char> > v , int r , int c )
 {
     int i1 = count(v,r,c,'T');
      int i2 = count(v,r,c,'X');
     if (i1 <= r/2) return 1;
     else if (i2 <= r/2) return 2;
     return 0;
 }

vector<int> cannons (vector<vector<char> > v , int r , int c)
{

    vector<int> can(8,-1);
    for(int j=0 ; j < c ; ++j)
    {
        int count =0;
       for(int i=7 ; i >= 0  ; --i)
       {
           
         if((v[i][j] == 'B') && (count < 3))
         count ++ ;
         else if((v[i][j] != ' ') && (count = 3))
         {count =0 ; break;}
         else if ((v[i][j] != 'B')  && (count < 3))
         count =0;
         else if (count == 3)
         {
             if (i >= 2) 
             {
             if ((v[i-1][j] == 'W') || (v[i-1][j] == 'T'))
             {can[j] = i-1 ;break;}
             else if (v[i-1][j] == 'B')
             break;
             else if (v[i-2][j] == 'B' ) {can[j] = i -1;break;}
             else { can[j] = i-2 ; break ;}
              }

              if(i==0) {break;}
              if(i == 1)
              { 
                if ((v[i-1][j] == 'W') || (v[i-1][j] == 'T') || (v[i-1][j] == ' ') )
             can[j] = i-1 ; break;
              }
          }
         
       } 
    }
    return can ;
}

vector<vector<char> > creator ()
{
    vector<vector<char> > vect{ { 'T','W', 'T','W','T','W','T', 'W' }, 
                               { ' ','W', ' ','W',' ','W',' ', 'W'}, 
                               {' ','W', ' ','W',' ','W',' ', 'W'},
                               {' ',' ',' ',' ',' ',' ',' ',' '},
                               {' ',' ',' ',' ',' ',' ',' ',' '},
                               {'B', ' ','B',' ','B',' ', 'B',' '},
                               {'B', ' ','B',' ','B',' ', 'B',' '},
                               { 'B','X', 'B','X','B','X','B', 'X' } };
    return vect;
}





vector<int > mover (vector <vector <char > > v , int r , int c ,int i , int j )
{
    vector <int > vect(3);

   if (i == 0)
   {
       vect[0] = 0;
       vect[1] = 0 ;
       vect [2] = 0;
       return vect;
   }

   else if (j == 0)
   {
       vect[0] = 0 ;
       if(v[i-1][0] != ' ' )
       vect[1] = 0;
       else vect[1] = 1 ;
       if(v[i-1][1] != ' ' )
       vect[2] = 0;
       else vect[2] = 1 ;
       return vect ;
   }

   else if (j == 7)
   {
      vect[2] = 0 ;
       if(v[i-1][j] != ' ' )
       vect[1] = 0;
       else vect[1] = 1 ;
       if(v[i-1][j-1] != ' ' )
       vect[0] = 0;
       else vect[0] = 1 ; 
       return vect;
   }
   
   else
   {
       if(v[i-1][j] != ' ' )
       vect[1] = 0;
       else vect[1] = 1 ;
       if(v[i-1][j+1] != ' ' )
       vect[2] = 0;
       else vect[2] = 1 ;
       if(v[i-1][j-1] != ' ' )
       vect[0] = 0;
       else vect[0] = 1 ; 
       return vect;
   }
   return vect;
}

vector<int > capturer (vector <vector <char > > v , int r , int c ,int i , int j )
{
    vector <int > vect(5);

   if (i == 0)
   {
       vect[0] = 0;
       vect[1] = 0 ;
       vect [2] = 0;
       
   }

   else if (j == 0)
   {
       vect[0] = 0 ;
       if(v[i-1][0] != 'W' )
       vect[1] = 0;
       else vect[1] = 1 ;
       if(v[i-1][1] != 'W' )
       vect[2] = 0;
       else vect[2] = 1 ;
       
   }

   else if (j == 7)
   {
      vect[2] = 0 ;
       if(v[i-1][j] != 'W' )
       vect[1] = 0;
       else vect[1] = 1 ;
       if(v[i-1][j-1] != 'W' )
       vect[0] = 0;
       else vect[0] = 1 ; 
    
   }
   
   else
   {
       if(v[i-1][j] != 'W' )
       vect[1] = 0;
       else vect[1] = 1 ;
       if(v[i-1][j+1] != 'W' )
       vect[2] = 0;
       else vect[2] = 1 ;
       if(v[i-1][j-1] != 'W' )
       vect[0] = 0;
       else vect[0] = 1 ; 
     
   }

   if(j == 0)
   {
    vect[3] = 0;
    if (v[i][j+1] != 'W')
    vect[4] = 0;
    else vect[4] = 1;
   }
   else if (j == 7)
   {
       vect[4] = 0;
    if (v[i][j-1] != 'W')
    vect[3] = 0;
    else vect[3] = 1;
   }
    
    else
    {
        if (v[i][j-1] != 'W')
    vect[3] = 0;
    else vect[3] = 1;
     if (v[i][j+1] != 'W')
    vect[4] = 0;
    else vect[4] = 1;
    }
    
    

   return vect;
}

char compliment (char c)
{
    if(c=='B') return 'W' ;
    else if (c == 'W')return 'B';
    if(c == 'T') return 'X';
    if(c == 'X') return 'T';
    else return ' ';
}

bool checkenemy (vector <vector <char > > v , int r , int c ,int i , int j , char c1)
{
    char c2 = compliment(c1);
     if(i==0)
     {
         if(j==0)
         {
             if(v[0][1] == c2)
             return true;
             else return false;
         }

         else if(j==7)
         {
             if(v[0][6] == c2)
             return true;
             else return false;
         }

        if((v[0][j-1] == c2) || (v[0][j+1] == c2)) 
        return true; else return false;

     }

    else if (j == 0)
    {
        if ((v[i-1][j] == c2) || (v[i-1][j+1] == c2) || (v[i][j+1] == c2)) return true;
        else return false;
    }

    else if (j == 7)
    {
        if ((v[i-1][j] == c2) || (v[i-1][j-1] == c2) || (v[i][j-1] == c2)) return true;
        else return false;
    }
    
    if ((v[i-1][j] == c2) || (v[i-1][j+1] == c2) || (v[i][j+1] == c2) || (v[i-1][j-1] == c2) || (v[i][j-1] == c2)) return true;
    else return false;

     
}

vector<int > retreater (vector <vector <char > > v , int r , int c ,int i , int j )
{
    vector <int > vect(3);

   if ((i >= 6) || (!checkenemy(v,r,c,i,j,'B')))
   {
       vect[0] = 0;
       vect[1] = 0 ;
       vect [2] = 0;
       return vect;
   }
 
   

   else if (j <= 1)
   {
       vect[0] = 0 ;
       if((v[i+1][j] != ' ' )||(v[i+2][j] =='B' ))
       vect[1] = 0;
       else vect[1] = 1 ;
       if((v[i+1][j+1] != ' ' )||(v[i+2][j+2] = 'B' ))
       vect[2] = 0;
       else vect[2] = 1 ;
       return vect ;
   }

   else if (j >= 6)
   {
      vect[2] = 0 ;
     if((v[i+1][j] != ' ' )||(v[i+2][j] == 'B' ))
       vect[1] = 0;
       else vect[1] = 1 ;
      if((v[i+1][j-1] != ' ' )||(v[i+2][j-2] == 'B' ))
       vect[0] = 0;
       else vect[0] = 1 ;
       return vect;
   }
   
   else
   {
       if((v[i+1][j] != ' ' )||(v[i+2][j] == 'B' ))
       vect[1] = 0;
       else vect[1] = 1 ;
      if((v[i+1][j-1] != ' ' )||(v[i+2][j-2] == 'B' ))
       vect[0] = 0;
       else vect[0] = 1 ;
       if((v[i+1][j+1] != ' ' )||(v[i+2][j+2] == 'B' ))
       vect[2] = 0;
       else vect[2] = 1 ;
       return vect;
   }
   return vect;
}

vector<Node *> getchilds (Node * n)
{
    int count=0;
     vector <vector < char > > v1 (8,vector<char> (8));
     vector <vector < char > > temp (8,vector<char> (8));
     v1 = n->data;
     vector<Node *> childs;

    

     for(int i=0 ; i< 8 ; ++i)
     {
         for(int j=0 ; j<8;++j)
         {
             if(v1[i][j] == 'B')
             {
                 count ++;


                vector<int> v5 = capturer (v1,8,8,i,j);
                 if(v5[0] == 1)
                {
                  temp = v1 ;
                
                  temp[i][j] = ' ';
                  temp[i-1][j-1] = 'B';
                  Node * n1 = new Node(8,8) ;
                n1->stalemate = false;
                  n1->data = temp;
                  n1->parent = n;
                  
                  childs.push_back(n1);
                }

                if(v5[1] == 1)
                {
                  temp = v1 ;
                 
                  temp[i][j] = ' ';
                  temp[i-1][j] = 'B';
                  Node * n1 = new Node(8,8) ;
                n1->stalemate = false;
                  n1->data = temp;
                  n1->parent = n;
                  
                  childs.push_back(n1);
                }


                if(v5[2] == 1)
                {
                  temp = v1 ;
                 
                  temp[i][j] = ' ';
                  temp[i-1][j+1] = 'B';
                  Node * n1 = new Node(8,8) ;
                n1->stalemate = false;
                  n1->data = temp;
                  n1->parent = n;
                  
                  childs.push_back(n1);
                }

                if(v5[3] == 1)
                {
                  temp = v1 ;
                 
                  temp[i][j] = ' ';
                  temp[i][j-1] = 'B';
                  Node * n1 = new Node(8,8) ;
                n1->stalemate = false;
                  n1->data = temp;
                  n1->parent = n;
                  
                  childs.push_back(n1);
                }

                if(v5[4] == 1)
                {
                  temp = v1 ;
                 
                  temp[i][j] = ' ';
                  temp[i][j+1] = 'B';
                  Node * n1 = new Node(8,8) ;
                n1->stalemate = false;
                  n1->data = temp;
                  n1->parent = n;
                  
                  childs.push_back(n1);
                }

                vector<int> v2 = mover (v1,8,8,i,j);
                
                if(v2[0] == 1)
                {
                  temp = v1 ;
                 
                  temp[i][j] = ' ';
                  temp[i-1][j-1] = 'B';
                  Node * n1 = new Node(8,8) ;
                n1->stalemate = false;
                  n1->data = temp;
                  n1->parent = n;
                  
                  childs.push_back(n1);
                }
                if(v2[1] == 1)
                {
                  temp = v1 ;
                 
                  temp[i][j] = ' ';
                  temp[i-1][j] = 'B';
                  Node * n1 = new Node(8,8) ;
                n1->stalemate = false;
                  n1->data = temp;
                  n1->parent = n;
                  
                  childs.push_back(n1);
                }
                if(v2[2] == 1)
                {
                  temp = v1 ;
                 
                  temp[i][j] = ' ';
                  temp[i-1][j+1] = 'B';
                  Node * n1 = new Node(8,8) ;
                n1->stalemate = false;
                  n1->data = temp;
                  n1->parent = n;
                  
                  childs.push_back(n1);
                }
                 

                vector<int> v7 = retreater (v1,8,8,i,j);

                if(v7[0] == 1)
                {
                  temp = v1 ;
                 
                  temp[i][j] = ' ';
                  temp[i+2][j-2] = 'B';
                  Node * n1 = new Node(8,8) ;
                n1->stalemate = false;
                  n1->data = temp;
                  n1->parent = n;
                  
                  childs.push_back(n1);
                }

                if(v7[1] == 1)
                {
                  temp = v1 ;
                 
                  temp[i][j] = ' ';
                  temp[i+2][j] = 'B';
                  Node * n1 = new Node(8,8) ;
                n1->stalemate = false;
                  n1->data = temp;
                  n1->parent = n;
                  
                  childs.push_back(n1);
                }


                if(v7[2] == 1)
                {
                  temp = v1 ;
                 
                  temp[i][j] = ' ';
                  temp[i+2][j] = 'B';
                  Node * n1 = new Node(8,8) ;
                n1->stalemate = false;
                  n1->data = temp;
                  n1->parent = n;
                  
                  childs.push_back(n1);
                }
              
               

             }
         }
     }

     /*vector<int> v9 = cannons(v1,8,8);
      for(int j =0 ; j<8 ; ++j)
      {
        if(v9[j] != -1)
        {
            int i = v9[j] ;
            temp = v1 ;
            
            temp[i][j] = ' ';
            Node * n1 = new Node(8,8) ;
                n1->stalemate = false;
                  n1->data = temp;
                  n1->parent = n;
                  
                  childs.push_back(n1);
        }
      } */


      


     return childs;
}

vector<vector < char> > flipper(vector<vector<char> > v)
{
    vector<vector<char> > v1 (8,vector<char> (8,' '));
    for(int i=0 ; i<8 ; i++)
    {
        for(int j =0 ; j<8 ; j++)
        {
           v1[i][j] = compliment(v[7-i][j]) ;
        }
    }

    

    return v1;

}

int value (Node * n)
{
    int r=8,c=8;
    vector<vector<char> > v = n->data;
    int bth = count(v,r,c,'X');
    int wth = count (v,r,c,'T');
    int ws = count (v,r,c,'W');
    int bs = count (v,r,c,'B');
    vector<int> cnns = cannons(v,8,8);
    int c3=0;
    for(int i=0;i<8;++i)
    {
        if(cnns[i] != -1)
        c3++;
    }
    v = flipper(v);
     cnns = cannons(v,8,8);
    
    for(int i=0;i<8;++i)
    {
        if(cnns[i] != -1)
        c3--;
    }

    int c1 = 13 * (-wth + bth);
    int c2 = 1 * (-ws + bs);
    return (c1 + c2 + 5 * c3);
}

vector < Node *> getwhitechilds(Node * n)
{
   vector<vector<char > > v = n->data;
   v = flipper(v);
   n->data = v;
   vector<Node * > v1 = getchilds(n);
   for(int i=0 ; i< v1.size() ; ++i)
   {
       Node * temp = v1[i];
       v = temp->data;
       
       v = flipper(v);
       temp->data = v;
       v1[i] = temp;
   }
   return v1;
}

Node * minimax(Node * n , int depth , bool maximising , int alpha , int beta )
{
    if(depth == 3)
    {
        if(maximising)
        n->set = value(n);
        else n->set = value(n);
        return n;
    }

    if(maximising)
    {
        int best = MIN ;
        Node * answer = new Node(8,8);
        vector<Node * > c = getchilds(n);
        for(int i =0 ; i < c.size() ; ++i)
        {
            Node * n1 = new Node(8,8);
            n1 = minimax(c[i],depth+1,false,alpha,beta );
            if(value(n1) > best)
            {
                answer = c[i];
                 best = value(n1);
                 if(best > alpha)
                 alpha = best;
                
            }
        }

       

        return answer;
    }

    else
    {
       
         int best = MAX ;
        Node * answer = new Node(8,8);
        vector<Node * > c = getwhitechilds(n);
        for(int i =0 ; i < c.size() ; ++i)
        {
            Node * n1 = new Node(8,8);
            n1 = minimax(c[i],depth+1,true,alpha,beta );
            if(value(n1) < best)
            {
                answer = c[i];
                 best = value(n1);
                 if(best < beta)
                 beta = best;
                 
            }
        }
        return answer;
    }
    
}


string getmsg (vector <vector<char> > v1 , vector<vector<char> > v11 , bool black)
{
   string move = "";

 int bs = count(v1,8,8,'B') + count(v1,8,8,'X');
 int ws = count(v1,8,8,'W') + count(v1,8,8,'T');
 int bs11 = count(v11,8,8,'B') + count(v11,8,8,'X');
 int ws11 = count (v11,8,8,'W') + count(v11,8,8,'T');

 int flipflop=0;

 for(int i=0 ; i<8 ; ++i)
 {
   for(int j=0 ; j<8 ; ++j)
   {
     if(v1[i][j] != v11[i][j])
     flipflop ++;
   }
 }

 if (flipflop == 2)
 {
   string move1 = "S";
   string move2 = "M";
   
     for (int i=0 ; i<8 ; ++i)
     {
       for(int j=0; j<8 ; ++j)
       {
         if(v1[i][j] != v11[i][j])
         {
           std::string s8 = std::to_string(i);
              std::string s9 = std::to_string(j);
            if(v1[i][j] == ' ')
            {
              string s3 = " " + s8 + " " + s9;

              
              move1 = "S" + s3;
            }
            else
            {
               string s3 = " " + s8 + " " + s9;
               move2 = "M" + s3;
               move2 = " " + move2;
            }
         }
       }
     }
     move = move1 + move2 ;
     return move;
   
   
 }

 else if (flipflop == 1)
 {
   
   string move;
    string move1 = "S";
   string move2 = "B";
   for(int i=0 ; i<8 ; ++i)
   {
     for(int j=0 ; j< 8 ; ++j)
     {
       std::string s8 = std::to_string(i);
       std::string s9 = std::to_string(j);
       if(v1[i][j ] != v11[i][j])
        {
          string s3 = " " + s8 + " " + s9;
          move2 = "B" + s3;
          move2 = " " + move2;
          
            if((v11[i][j] == 'T') || (v11[i][j] == 'W'))
            {
              int count =0;
              
              for(int i1 =7 ; i1 >= 1 ; i1 --)
              {
                if(v1[i1][j] == 'B')
                {
                
                  count ++;
                 
                }

                else 
                { 
                  if(count >= 3)
                  {
                    
                     s8 = std::to_string(i1+1);
                      s3 = " "+s8 + " " + s9;
                     move1 = "S" + s3;
                     move = move1 + move2 ; return move; break;
                  } else count = 0;
                }
              }
            }

            else 
            {

                int count =0;
              for(int i1 =0 ; i1 <= 5 ; i1 ++)
              {
                if(v1[i1][j] == 'W')
                {
                  count ++;
                }

                else if (v1[i1][j] != 'W')
                {
                  if(count >= 3)
                  {
                     s8 = std::to_string(i1-1);
                     string s3 = " "+s8 + " " + s9;
                     move1 = "S" + s3;
                     move = move1 + move2 ;  return move;break;
                  } else count = 0;
                }
              }

            }
          
       }
     }
   }
   return move;
 }


 else if (flipflop == 0)
 {
   string move = "";
    string move1 = "S";
   string move2 = "B";
   if(black)
   {
    vector<int> vcnns = cannons(v11 , 8 ,8);
    for(int j=0 ; j<8 ; j++)
      {
      int i1 = vcnns[j];
      if(vcnns[j] != -1) 
      {
        if(v11[i1][j] == ' ')
        {
          std::string s8 = std::to_string(i1);
          std::string s9 = std::to_string(j);
          string s3 = " " + s8 + " " + s9;
          move2 = "B" + s3;
          move2 = " " + move2;
           int count =0;
              
              for(int i1 =7 ; i1 >= 1 ; i1 --)
              {
                if(v1[i1][j] == 'B')
                {
                  
                  count ++;
                  
                }

                else 
                {  
                  if(count >= 3)
                  {
                    
                     s8 = std::to_string(i1+1);
                      s3 = " "+s8 + " " + s9;
                     move1 = "S" + s3;
                     move = move1 + move2 ; return move; break;
                  } else count = 0;
                }
              }
        }
      }
      }
   }

   else 
   {
     
      v11 = flipper(v11);
      vector<int> vcnns = cannons(v11 , 8 ,8);
    for(int j=0 ; j<8 ; j++)
      {
      int i1 = vcnns[j];
      if(vcnns[j] != -1) 
      {

        if(v11[i1][j] == ' ')
        {
          std::string s8 = std::to_string(7-i1);
          std::string s9 = std::to_string(j);
          string s3 = " " + s8 + " " + s9;
          move2 = "B" + s3;
          move2 = " " + move2;
           int count =0;
              
              for(int i1 =7 ; i1 >= 1 ; i1 --)
              {
                if(v11[i1][j] == 'B')
                {
                  
                  count ++;
            
                }

                else 
                {  
                  if(count >= 3)
                  {
                    
                     s8 = std::to_string(7-i1);
                      s3 = " "+s8 + " " + s9;
                     move1 = "S" + s3;
                     move = move1 + move2 ; return move; break;
                  } else count = 0;
                }
              }
        }
      }
      }


   }


 }  

}

vector< vector < char > >  readmsg (string msg , vector <vector < char > > v)
{
    vector<string> answer = split(msg);
    vector<vector<char> > v1 = v;
    int i1 = getinteger(answer[1]);
    int j1 = getinteger(answer[2]);
    int i2 = getinteger(answer[4]);
    int j2 = getinteger(answer[5]);
    if(answer[3] == "B")
    {
        v1[i2][j2] = ' ';
        return v1 ;
    }
    if(answer[3] == "M")
    {
      v1[i1][j1] = ' ';
      v1[i2][j2] = v[i1][j1];
      return v1;
    }
    return v1;
}

string optimiser(string msg)
{
    vector<string> vs = split(msg);
    string s1 = vs[0];
    string s2 = vs[1];
    string s3 = vs [2];
    string s4 = vs [3];
    string s5 = vs[4];
    string s6 = vs[5];
    string s = s1 +" "+ s3+" " + s2+" " + s4+" " + s6+" " + s5;
    return s;
}

int main(int argc, char  **argv)
{
  vector <vector < char > > v1 (8,vector<char> (8));
  vector <vector < char > > v11 (8,vector<char> (8));
  vector <vector < char > > temp (8,vector<char> (8));
  v1 = creator ();
  v11 = creator();
  string s;string s1,s2,s3,s4,s5,s6;
  cin >> s1 ;
  cin >> s2;
  cin >> s3;
  cin >> s4;
  bool Black ;
  if(s1 == "0")
  {
    Black = true;
  } 
  if(s1 == "1")
   Black = false;
 int count = 0;
 Node * n2 = new Node(8,8);
 Node * n3 = new Node(8,8);
 if(Black){
 while(count < 12345)
 {
   
   n2 -> data = v1;
  
    n3 = minimax(n2,0,true,MIN,MAX);
   v11 = n3->data;
   v11 =  flipper(v11);
   
   string g = getmsg(v11,v1,true);
   g = optimiser(g);
   cout << g << endl;
   
   cin >> s1;
   cin >> s2;
   cin >> s3;
   cin >> s4;
   cin >> s5;
   cin >> s6;
   s = s1 + " " + s2 + " " + s3 + " " + s4 + " " + s5 + " " + s6; 
     
     s = optimiser(s);
   v1 = readmsg(s,v11);

   
   count ++;
   

 }}


 if(!Black){
 while(count < 12345)
 {
   
 
   cin >> s1;
   cin >> s2;
   cin >> s3;
   cin >> s4;
   cin >> s5;
   cin >> s6;
   s = s1 + " " + s2 + " " + s3 + " " + s4 + " " + s5 + " " + s6; 
     
     s = optimiser(s);
   v1 = readmsg(s,v11);


   n2 -> data = v1;
  
    n3 = minimax(n2,-1,false,MIN,MAX);
   v11 = n3->data;
   
   
   string g = getmsg(v11,v1,false);
   g = optimiser(g);
   cout << g << endl;
   
   
   
   count ++;
   

 }}



 

  return 0;
}   