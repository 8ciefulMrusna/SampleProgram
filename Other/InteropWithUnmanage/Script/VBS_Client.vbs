Option Explicit 

Dim ret
Dim str1
Dim i1
Dim str2
Dim i2
        
str1 = "test1,"
i1 = 1
str2 = "test2,"
i2 = 2

'----------------------------------------------------------

' <VB_COM.ClassTest>

Dim obj
Set obj = CreateObject("VB_COM.ClassTest")

'����I��
ret = obj.MethodTest2(str1, i1, str2, i2)
'MethodTest2�́A�����E�߂�l�̌^��S��Variant�^�ɕύX�����B

'MsgBox
Call MsgBox( _
  "ret:" & ret & vbCrLf & _
  "str1:" & str1 & vbCrLf & "i1:" & CStr(i1) & vbCrLf & _
  "str2:" & str2 & vbCrLf & "i2:" & CStr(i2), vbOKOnly)

'�ُ�I���i�G���[�n���h���ցj
'ret = obj.MethodTest2("", i1, str2, i2)

'----------------------------------------------------------

' <VC_COM.ClassTest>

Set obj = CreateObject("VC_COM.ClassTest")

'����I��
Call MsgBox(obj.MethodTest("��������", "�ɂ���"))
'�����E�߂�l�̌^�����ׂ�BSTR�ł���ΌĂׂ�͗l�B