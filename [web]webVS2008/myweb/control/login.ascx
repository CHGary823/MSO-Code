<%@ Control Language="c#" AutoEventWireup="false" Codebehind="login.ascx.cs" Inherits="web.control.login" TargetSchema="http://schemas.microsoft.com/intellisense/ie5"%>

<%
if(Session["userid"]==null)
{
%>
<DIV id="login" align="center"><IMG alt="�~̖���" src="images/col_login.gif">
	<DL>
		<DT>�~&nbsp;̖
			<DD>
				<asp:textbox id="tbuserid" runat="server" Columns="16" MaxLength="16"></asp:textbox><FONT face="�����w">&nbsp;</FONT>
				<DT>�� �a
					<DD>
						<asp:textbox id="tbuserpwd" runat="server" Columns="16" MaxLength="16" TextMode="Password"></asp:textbox><FONT face="�����w">&nbsp;</FONT>
						<DT>��C�a
							<DD>
								<asp:textbox id="tbverifycode" runat="server" Columns="4" MaxLength="4" Width="40px"></asp:textbox><IMG id="imgVerify" style="WIDTH: 56px; CURSOR: hand; HEIGHT: 20px" onclick="this.src=this.src"
									alt="�����壿�c�����Q" src="VerifyCode.aspx"></DD></DL>
	<DIV class="btn">
		<asp:button id="btnlogin" style="CURSOR: hand" runat="server" CssClass="submit"></asp:button>&nbsp;<A href="register.aspx"><IMG src="images/btn_reg.gif" border="0"></A><A href="forgetpassword.aspx"><IMG src="images/btn_forget.gif" border="0"></A>
	</DIV>
</DIV>
<%}
else
{%>
<DIV align="center" id="login">
	<img alt="�~̖���" src="images/col_login.gif">
	<DL>
		<b>
			[ī��]
			�gӭ��</b>
		<br>
		<DT>�� ̖
			<DD>
				<%=Session["userid"]%>
				<DT>�� ��
					<DD>
						<%=weblevel%>
						<DT>�� ��<DD><%=Session["webgold"]%>��</DD>
	</DL>
	<DIV class="btn">
		<asp:Button CssClass="button_1" id="Button1" Text="�˳��Wվ" runat="server"></asp:Button>
	</DIV>
</DIV>
<%}%>
