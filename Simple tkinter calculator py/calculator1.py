# -*- coding: utf-8 -*-
"""
Created on Thu May  7 23:01:13 2020

@author: Rahul
"""


import tkinter as tk

#Basic window
""" Ceates the basic window"""
window = tk.Tk()
window.title('Calculator experiment')
window.resizable(0,0)
window.configure(bg='grey')
#p=tk.PhotoImage(file='calculator1.ico')
#window.iconphoto('false','calculator1.ico')
L1=tk.Label(window,text='Thanks for using the prototype :-)',bg='#fed',width=42,font=('Times New Roman',8),).grid(row=0,column=0,columnspan=4,ipadx=15)
        #Backend
input_text = tk.StringVar()
output_text = tk.StringVar()
expression = ''
BUTTONLIST=[]
class Cbuttons(tk.Button):
    """Button objects for application"""
    def format_n(self, title):
        """Format for numerical buttons (0,1,2,3,4,5,6,7,8,9,.) """
        self.name = title
        self['text']= title
        self['bg']='#456899'
        self['fg']='white'
        self['command']= self.b_click
        self['width']= 6
        self['height']= 2
        self['padx']= 7
        self['bd']=6
    def format_O(self, title):
        """Format for operation buttons (+,-,*,/,(,)) """
        self.name = title
        self['text']= title
        self['bg']='#556555'
        self['command']= self.b_click
        self['width']= 4
        self['padx']= 5
        self['bd']=6
        self['font']=('Times New Roman',14,'bold')
    def b_click(self):
        """ Operation done by buttons to add input"""
        global expression
        expression += str(self.name)
        input_text.set(expression)
    
def clickC():
    """ Operation of CLEAR(C) button """
    global expression
    expression =''
    input_text.set(expression)
    output_text.set(expression)
def clickeq():
    """ Operation of equal(=) button"""
    global expression
    out=str(eval(expression))
    output_text.set(expression)
    expression = out
    input_text.set(expression)
def clickDEL():
    """ Operation of delete(DEL) button"""
    global expression
    expression = expression[:len(expression)-1]
    input_text.set(expression)
def clickQUIT():
    """ Operation of OUIT button"""
    pop=tk.Toplevel(window, bg='#dde')
    pop.title("Quit?")
    pop.overrideredirect(1)
    tk.Label(pop,text='Do you want to quit?', font=('times new roman',18)).grid(row=0,columnspan=2)
    for i in BUTTONLIST:
        i['state']='disabled'
    def clickNO():
        pop.destroy()
        for i in BUTTONLIST:
            i['state']='normal'
    tk.Button(pop,text='yes',bg='red',fg='white',width=8,height=2,command=window.destroy).grid(row=1,column=0)
    tk.Button(pop,text='no',bg='red',fg='white',width=8,height=2,command=clickNO).grid(row=1,column=1)
    
    #Screen
input_field = tk.Label(window, textvariable=input_text, anchor='e',bg='white', font=('Times New Roman',14), width=26)
output_field = tk.Label(window, textvariable=output_text, anchor='e', font=('Times New Roman',12), width=27)
input_field.grid(row=2,column=0,columnspan=4,ipady=14,ipadx=10)
output_field.grid(row=1,column=0,columnspan=4,ipady=8,ipadx=17)
    #Buttons
"declarions"
bC=Cbuttons(window, text='C',width = 9, height =1,padx=15,bd=5,command=clickC,font=('Times New Roman',14,'bold'))
bdel=Cbuttons(window, text='DEL',width = 7, height =2,padx=7,bd=3,command=clickDEL)
bquit=Cbuttons(window, text='QUIT',width = 6, height =2,padx=7,bd=5,fg='white',bg='red',command= clickQUIT)
bequal=Cbuttons(window, text='=',width = 9, height =1,padx=15,bd=5,command=clickeq,font=('Times New Roman',14,'bold'))
b0=Cbuttons(window)
b1=Cbuttons(window)
b2=Cbuttons(window)
b3=Cbuttons(window)
b4=Cbuttons(window)
b5=Cbuttons(window)
b6=Cbuttons(window)
b7=Cbuttons(window)
b8=Cbuttons(window)
b9=Cbuttons(window)
bdot=Cbuttons(window)

bplus=Cbuttons(window ,height =2,pady=15)
bminus=Cbuttons(window, height =1)
bmulti=Cbuttons(window, height =1)
bdiv=Cbuttons(window, height =1)
bobr=Cbuttons(window, height=1)
bcbr=Cbuttons(window, height=1)

BUTTONLIST=(bC,bdel,bquit,bequal,b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,bdot,bplus,bminus,bmulti,bdiv,bobr,bcbr)
"formattig"
bdot.format_n('.')
b_num = (b0,b1,b2,b3,b4,b5,b6,b7,b8,b9)
b_op = (bplus,bminus,bmulti,bdiv,bobr,bcbr)
op_text = ('+','-','*','/','(',')')
for i in b_num :
    i.format_n(str(b_num.index(i)))
for i in b_op:
    i.format_O(str(op_text[b_op.index(i)]))

"positioning"
bC.grid(row=3,column=0,columnspan=2)
bdel.grid(row=3,column=2)
bquit.grid(row=3,column=3)

b7.grid(row=5,column=0)
b8.grid(row=5,column=1)
b9.grid(row=5,column=2)
b4.grid(row=6,column=0)
b5.grid(row=6,column=1)
b6.grid(row=6,column=2)
b1.grid(row=7,column=0)
b2.grid(row=7,column=1)
b3.grid(row=7,column=2)
bdot.grid(row=8,column=0)
b0.grid(row=8,column=1)

bobr.grid(row=4,column=0)
bcbr.grid(row=4,column=1)
bdiv.grid(row=4,column=2)
bmulti.grid(row=4,column=3)
bminus.grid(row=5,column=3)
bplus.grid(row=6,column=3,rowspan=2)
bequal.grid(row=8,column=2,columnspan=2)




        #applicatin initiation

window.mainloop()

