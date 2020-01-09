#include <iostream>
using namespace std;

int main()
{
  int n;//number of case
  cin>>n;
  for(int i =1;i<=n;i++)
  {
      int s;
      cin>>s>>ws;
      string engine_name;
      string engine_names_list[s];
      int first_line[s];
      int number_of_repatation[s];
      for(int j=0;j<s;j++)
      {
          getline(cin,engine_name);
          engine_names_list[j]=engine_name;
          first_line[j]=0;
          number_of_repatation[j]=0;
      }
      int q;
      cin>>q>>ws;
      string quireis[q];
      string user_input;
      for(int k=0;k<q;k++)
      {
          getline(cin,user_input);
          quireis[k]=user_input;
          for(int j=0;j<s;j++)
          {
              if(engine_names_list[j]==user_input)
              {
                  number_of_repatation[j]+=1;
                  if(number_of_repatation[j]==1)
                  {
                    first_line[j] = k;
                  }

              }
          }
      }
      string engine_in_use;
      bool repatation = true;
      for(int j=0;j<s;j++)
      {
          for(int k=j+1;k<s-1;k++)
          {
              if(first_line[j]<first_line[k])
              {
                  swap(first_line[j],first_line[k]);
                  swap(engine_names_list[j],engine_names_list[k]);
                  swap(number_of_repatation[j],number_of_repatation[k]);
              }
              if (number_of_repatation[j]==0)
              {
                  engine_in_use = engine_names_list[j];
                  repatation = false;
              }
          }
      }
      int engine_switch =0;
      int index_loop_break;
      if(repatation==true)
      {
          engine_in_use = engine_names_list[0];
          engine_switch++;
          for(int k=0;k<q;k++)
          {
              if(quireis[k]==engine_in_use)
              {
                  for(int j=0;j<s;j++)
                  {
                      number_of_repatation[j]=0;
                      first_line[j]=0;
                      for(int m=k;k<q;m++)
                      {
                          if(engine_names_list[j]==quireis[k])
                          {
                              number_of_repatation[j] +=1;
                              if(number_of_repatation[j]==1)
                              {
                                  first_line[j] = k;
                              }
                          }
                      }
                  }
                  for(int j=0;j<s;j++)
                    {
                        for(int k=j+1;k<s-1;k++)
                            {
                                if(first_line[j]<first_line[k])
                                    {
                                        swap(first_line[j],first_line[k]);
                                        swap(engine_names_list[j],engine_names_list[k]);
                                        swap(number_of_repatation[j],number_of_repatation[k]);
              }
              if (number_of_repatation[j]==0)
              {
                  engine_in_use = engine_names_list[j];
                  repatation = false;
              }
              else
              {
                  engine_in_use = engine_names_list[0];
              }
          }
      }




              }
          }

      }
      cout<<"Case #"<<n<<" : "<<engine_switch<<endl;
  }

}
