//
//  SortedCollection.hpp
//  Lab: Sorted Collection 3.4
//
//  Created by Coleton Watt on 1/24/22.
//

#ifndef SortedCollection_hpp
#define SortedCollection_hpp

#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>

#include "Collection.h"

using namespace std;
/*
template<typename Item>
class SortedCollection;
 */
template<typename Item>
class SortedCollection: public Collection<Item>{
public:
  
    SortedCollection();
    SortedCollection(int x);
    SortedCollection(Collection<Item> &x2);
    virtual void add(Item ndx2);
   

    SortedCollection<Item>& operator<<(Item x);

    SortedCollection<Item>& operator+(Item ndx2);
    
    
protected:
    int max;
    
};

template<typename Item>
SortedCollection<Item>::SortedCollection(){
    
}
template<typename Item>
SortedCollection<Item>::SortedCollection(int x){
    Collection<Item>::capacity = x;
}

template<typename Item>
SortedCollection<Item>& SortedCollection<Item>::operator+(Item ndx2){
    add(ndx2);
    return *this;
}

template<typename Item>
void SortedCollection<Item>::add(Item ndx2){
    //using Collection<Item>::elements;
    Collection<Item>::add(ndx2);
    //int n  = sizeof(Collection<Item>::elements) / sizeof(Collection<Item>::elements[0]);//
    int n = Collection<Item>::curSize;
    //Collection<Item>::elements.sort();
    //sort(Collection<Item>::elements, Collection<Item>::elements + n);
    
    int j,temp, i;
    for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(Collection<Item>::elements[i]>Collection<Item>::elements[j])
                {
                    temp  =Collection<Item>::elements[i];
                    Collection<Item>::elements[i]=Collection<Item>::elements[j];
                    Collection<Item>::elements[j]=temp;
                }
            }
        }
    for(int z = 0; z <  Collection<Item>::curSize; z++){
        //cout << Collection<Item>::elements[i];
        
    }
}
    
template<typename Item>
SortedCollection<Item>&  SortedCollection<Item>::operator<<(Item x){
    add(x);
    return *this;
}
   

#endif /* SortedCollection_hpp */
