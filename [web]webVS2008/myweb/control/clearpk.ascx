<%@ Control Language="c#" AutoEventWireup="false" Codebehind="clearpk.ascx.cs" Inherits="web.control.clearpk" TargetSchema="http://schemas.microsoft.com/intellisense/ie5"%>
<table cellspacing="1" cellpadding="1" width="528" border="0">
	<TR>
		<TD colspan="3">
			<P><b>��ϴ����:</b></P>
			<P>��ϴ������Ҫ�˳��[��</P>
			<p>ϴһ�c������Ҫ����<b><font color="#ff3333"><%=Application["game.clearpkgold"]%></font>��</b></p>
			<P>&nbsp;</P>
		</TD>
	</TR>
	<tr>
		<td style="WIDTH: 103px">��ꑎ�̖</td>
		<td style="WIDTH: 136px"><strong><%=Session["userid"]%></strong></td>
		<td><FONT face="����"></FONT></td>
	</tr>
	<tr>
		<td style="WIDTH: 103px; HEIGHT: 20px">��ɫ�б�</td>
		<td style="WIDTH: 136px; HEIGHT: 20px">
			<asp:DropDownList id="ddchalist" runat="server"></asp:DropDownList></td>
		<td style="HEIGHT: 20px">
			<asp:RequiredFieldValidator id="Requiredfieldvalidator6" runat="server" ErrorMessage="*" ControlToValidate="ddchalist"></asp:RequiredFieldValidator>Ո�x����Ҫ��ϴ�����Ľ�ɫ</td>
	</tr>
	<TR>
		<TD style="WIDTH: 103px; HEIGHT: 20px"><FONT face="�����w">��ϴ��</FONT></TD>
		<TD style="WIDTH: 136px; HEIGHT: 20px">
			<asp:TextBox id="tbpk" runat="server" MaxLength="14" Width="88px"></asp:TextBox></TD>
		<TD style="HEIGHT: 20px">
			<asp:RequiredFieldValidator id="RequiredFieldValidator1" runat="server" ControlToValidate="tbpk" ErrorMessage="*"></asp:RequiredFieldValidator>Ոݔ����Ҫ��ϴ�Đ�����</TD>
	</TR>
	<TR>
		<TD align="center" colSpan="3" height="10"><FONT face="����"></FONT></TD>
	</TR>
	<TR>
		<TD colspan="3" align="center">
			<asp:Button id="btnclear" runat="server" Text="��ϴ����" CssClass="button_1"></asp:Button>
		</TD>
	</TR>
</table>
<asp:RegularExpressionValidator id="RegularExpressionValidator1" runat="server" ErrorMessage="Ո�������" ValidationExpression="^\+?[1-9][0-9]*$"
	ControlToValidate="tbpk"></asp:RegularExpressionValidator>
