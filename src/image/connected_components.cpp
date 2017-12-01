#include "image/connected_components.h"
#include<deque>
#include<utility>

ConnectedComponents::ConnectedComponents(){}

int ConnectedComponents::getmedian(const Image& I){
    
        BrightnessHistogram hist(I);
        std::vector<int>thresholds(hist.getThresholds());
        int len=thresholds.size();
        // sort(thresholds.begin(),thresholds.begin()+len);

        if(len%2==1){return thresholds[len/2];}
        return (thresholds[len/2]+thresholds[len-1/2])/2;
    }

int ConnectedComponents::issafe(Image I,int **status,int i,int j,bool **visited){
    if(i>=0&&  j>=0&&   i<I.getHeight()   &&j<I.getWidth()){
         if(status[i][j]==1&&!visited[i][j]){return 1; }}
    return 0;
}

// void ConnectedComponents::DFS(Image& I,int i,int j,bool **visited,int **status,Color col){


//   //          std::cout<<i<<" "<<j<<" "<<visited[i][j]<<endl;

//             visited[i][j]=true;
//             I[i][j].setColor(col);

//             for(int i1=-1;i1<2;i1++){
//                 for(int j1=-1;j1<2;j1++){
//                     if(i1!=0&&j1!=0){
//                         if(issafe(I,status,i+i1,j+j1,visited)){DFS(I,i+i1,j+j1,visited,status,col); }
                        
//                     }
//                 }
//             }
//     }        

void ConnectedComponents::DFS(Image& I,int i,int j,bool **visited,int **status,Color col){
    std::deque< std::pair<int, int> > q;
    q.push_back(std::make_pair(i, j));
    visited[i][j] = true;
    int count = 1;

    while(!q.empty()){
        pair<int, int> temp = q.front();
        q.pop_front();
        i = temp.first;
        j = temp.second;

        // if(visited[i][j]){continue;}
        
        I[i][j].setColor(col);

        for(int i1 = i-1; i1 <= i+1; ++i1){
            for(int j1 = j-1; j1 <= j+1; ++j1){
                if(i1<0||j1<0||i1>=I.getHeight()||j1>=I.getWidth()){
                    continue;
                }
                if((!visited[i1][j1]) && status[i1][j1] == 1){
                    q.push_back(make_pair(i1, j1));
                    visited[i1][j1] = true;
                    // std::cout<<++count<<std::endl;
                }
            }
        }
    }
}
    
Image ConnectedComponents::formcomponents(const Image& I){
        
        
        int mid=getmedian(I);
        // cout<<mid<<endl;
        //  int mid=142;
        Color WHITE(255,255,255),BLACK(0,0,0);
        Image binary=I.getBinaryImage(mid,BLACK,WHITE);
        // return binary;
        
        Color RED(255,0,0),BLUE(0,255,0),GREEN(0,0,255),CYAN(0,255,255),MAGENTA(255,0,255),YELLOW(255,255,0);
        Color colors[6]={RED,BLUE,GREEN,CYAN,MAGENTA,YELLOW};

        int height=I.getHeight();
        int width=I.getWidth();
        int count=0;

         bool **visited=new bool*[height];
         for(int i=0;i<height;i++){visited[i]=new bool[width];   for(int j=0;j<width;j++){visited[i][j]=false;}   }

        // for(int i=0;i<height;i++){
        //     for(int j=0;j<width;j++){
        //         cout<<visited[i][j];
        //     }
        //     cout<<endl;
        // }


         int **status=new int*[height];
        for(int i=0;i<height;i++){status[i]=new int[width];}
    
        //bool visited[height][width];
        //memset(visited, 0, sizeof(visited));
 
    
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){ //  visited[i][j]=false;
                if(binary[i][j].brightness()==0){
                    status[i][j]=0;
                }
                else{
                    status[i][j]=1;
                }
            }
        }


        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(!visited[i][j]&&status[i][j]){DFS(binary,i,j,visited,status,colors[count%6]);
                    count++;
                }
                //std::cout<<count<<std::endl;
                
        }}
        return binary;
    }
