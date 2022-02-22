/*
 
 **/


#pragma once

class TestClassInterface{
    public:
        virtual ~TestClassInterface()=default;
        virtual void setData(int i)=0;
        virtual int  getData()=0;

};



