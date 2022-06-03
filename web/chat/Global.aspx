<Script Language="VB" Runat="Server">
Sub Session_onstart                     '统计在线人数，每进来1个用户cnt加1
    Application.Lock
    Application("cnt")=Application("cnt")+1     
    Application.Unlock
End Sub
Sub Session_onend                     '统计在线人数，每离开1个用户cnt减1
    Application.Lock
    Application("cnt")=Application("cnt")-1     
    Application.Unlock
End Sub
</Script>
