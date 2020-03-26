//
// Created by gremo on 2/13/20.
//

#ifndef UNTITLED_SPACE_H
#define UNTITLED_SPACE_H



    class Space
    {
    private:
        int height;
        bool open;
        int maxHeight;
        int numAdj;

    public:
        Space(int newId,int max);
        int getHeight();
        void setHeight(int newHeight);
        int getMaxHeight();
        void setMaxHeight(int newHeight);
        ~Space();
        int getNumAdj();
        void setNumAdj(int newNumAdj);
        bool isEmpty();
        void setEmpty(bool empty);
        bool build();
        bool unbuild();
        int id;
        bool addAdj(int addId);
        bool isAdj(int spaceId);
        int *adjList;

    };



#endif //UNTITLED_SPACE_H
