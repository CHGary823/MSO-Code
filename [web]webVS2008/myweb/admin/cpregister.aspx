<%@ Page language="c#" Codebehind="cpregister.aspx.cs" AutoEventWireup="false" Inherits="web.admin.cpregister" %>
<%@ Register TagPrefix="uc1" TagName="cptop" Src="../control/cptop.ascx" %>
<%@ Register TagPrefix="uc1" TagName="cpmenu" Src="../control/cpmenu.ascx" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
  <HEAD>
		<title>admincp</title>
<meta content="Microsoft Visual Studio .NET 7.1" name=GENERATOR>
<meta content=C# name=CODE_LANGUAGE>
<meta content=JavaScript name=vs_defaultClientScript>
<meta content=http://schemas.microsoft.com/intellisense/ie5 name=vs_targetSchema>
<SCRIPT language=JavaScript src="Common/JavaScript/Menu.js"></SCRIPT>
<LINK href="Common/CSS/Default.CSS" type=text/css rel=stylesheet ><LINK href="Common/CSS/menuStyleXP.CSS" type=text/css rel=stylesheet >
  </HEAD>
<body MS_POSITIONING="GridLayout">
<form id=Form1 method=post runat="server"><uc1:cptop id=Cptop1 runat="server"></uc1:cptop>
<table id=Table1 cellSpacing=1 cellPadding=3 width=780 border=0>
  <tr>
    <td vAlign=top width=207 rowSpan=2>
      <table cellSpacing=0 cellPadding=0 width="100%" align=center border=0 
      >
        <tr bgColor=#bcbcbc>
          <td>
            <table cellSpacing=1 cellPadding=10 width="100%" border=0 
            >
              <tr bgColor=#efefef>
                <td vAlign=top height=498><uc1:cpmenu id=Cpmenu1 runat="server"></uc1:cpmenu></TD></TR>
              <tr bgColor=#f9f9f9>
                <td height=80>
                  <div align=center>
                  <p><font color=#ff6633 
                  ><A href="../logout.aspx" target=_blank ><b 
                  ><font color=#ff6666 
                  >�]�N�˳�</FONT></B></A></FONT></P></DIV></TD></TR></TABLE></TD></TR></TABLE></TD>
    <td vAlign=top width=556>
      <table id=Table2 cellSpacing=0 cellPadding=0 width=563 align=center 
      border=0>
        <tr bgColor=#bcbcbc>
          <td>
            <table id=Table3 cellSpacing=1 cellPadding=8 width="100%" border=0 
            >
              <tr bgColor=#efefef>
                <td vAlign=top align=left height=350>
                  <TABLE id=Table4 cellSpacing=1 cellPadding=1 width="60%" 
                  border=0>
                    <TR>
                      <TD style="WIDTH: 107px; HEIGHT: 22px" colSpan=2 
                      ><b 
                    >�]������</B></TD></TR>
                    <TR>
                      <TD style="WIDTH: 107px; HEIGHT: 22px" 
                      >�Ƿ��_���]��</TD>
                      <TD style="HEIGHT: 22px"><asp:radiobutton id=rbregyes runat="server" GroupName="allowreg" Text="�_��"></asp:radiobutton><asp:radiobutton id=rbregno runat="server" GroupName="allowreg" Text="�P�]"></asp:radiobutton></TD></TR>
                    <TR>
                      <TD style="WIDTH: 107px; HEIGHT: 24px" 
                      >�]��ٛ�ͽ���</TD>
                      <TD style="HEIGHT: 24px"><asp:textbox id=tbgivegold runat="server" MaxLength="4"></asp:textbox><asp:regularexpressionvalidator id=RegularExpressionValidator1 runat="server" ErrorMessage="*" ControlToValidate="tbgivegold" ValidationExpression="^\d{1,4}$"></asp:regularexpressionvalidator><asp:requiredfieldvalidator id=RequiredFieldValidator1 runat="server" ErrorMessage="*" ControlToValidate="tbgivegold"></asp:requiredfieldvalidator></TD></TR>
                    <TR>
                      <TD style="WIDTH: 107px">�P�]�]����ʾ</TD>
                      <TD style="WIDTH: 107px"><asp:textbox id=tbstopreg runat="server" TextMode="MultiLine" Rows="10" Width="208px"></asp:textbox></TD></TR>
                    <TR>
                      <TD style="WIDTH: 107px"></FONT></TD>
                      <TD style="WIDTH: 107px"><asp:button id=btnedit runat="server" Text="�� ��"></asp:button></TD></TR></TABLE></FONT></TD></TR></TABLE></TD></TR></TABLE></TD></TR></TABLE></FORM>
	</body>
</HTML>
