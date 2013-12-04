//
//  SearchWindow.h
//  FastDTW-x
//
//  Created by Melo Yao on 12/4/13.
//  Copyright (c) 2013 melo.yao. All rights reserved.
//

#ifndef __FastDTW_x__SearchWindow__
#define __FastDTW_x__SearchWindow__

#include "Foundation.h"
#include <vector>
#include <algorithm>
FD_NS_START
class SearchWindow;

class SearchWindowIterator
{
    JInt _currentI;
    JInt _currentJ;
    const SearchWindow* _window;
    JBool _hasMoreElements;
    JInt _expectedModCount;
    
protected:
    SearchWindowIterator(SearchWindow* w);
    ~SearchWindowIterator();
public:
    bool hasNext();
    
};

using namespace std;
class SearchWindow
{
    vector<JInt> _minValues;
    vector<JInt> _maxValues;
    JInt _maxJ;
    JInt _size;
    JInt _modCount;
    
    void expandSearchWindow(JInt radius);
public:
    SearchWindow(JInt tsIsize, JInt tsJsize);
    
    virtual ~SearchWindow();
    
    bool isInWindow(JInt i,JInt j) const;
    
    JInt minI() const;
    
    JInt maxI() const;
    
    JInt minJForI(JInt i) const;

    JInt maxJForI(JInt i) const;
    
    JInt maxJ() const;
    
    JInt size() const;
    
    JInt getModCount() const;
    
protected:
    void expandWindow(JInt radius);
    
    void markVisited(JInt col, JInt row);
    
};

FD_NS_END
#endif /* defined(__FastDTW_x__SearchWindow__) */