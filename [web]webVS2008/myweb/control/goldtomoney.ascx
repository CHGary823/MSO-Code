<%@ Control Language="c#" AutoEventWireup="false" Codebehind="goldtomoney.ascx.cs" Inherits="web.control.goldtomoney" TargetSchema="http://schemas.microsoft.com/intellisense/ie5"%>
<table cellspacing="1" cellpadding="1" width="528" border="0">
	<TR>
		<TD colspan="3">
			<P><b>ُ�I�[���:</b></P>
			<P>ُ�I�[��Ų���Ҫ�˳��[��</P>
			<P>ُ�I�ɹ����[��Ō�������ľW���y��,Ո��ꑾW���y���Iȡ�[���</P>
			<p>ÿ1�����ſ��ԓQȡ<b><font color="#ff3333"><%=Application["game.goldtomoney"]%></font>�[���</b></p>
			<P><FONT face="����"></FONT>&nbsp;</P>
		</TD>
	</TR>
	<tr>
		<td style="WIDTH: 76px">��ꑎ�̖</td>
		<td style="WIDTH: 136px"><strong><%=Session["userid"]%></strong></td>
		<td><FONT face="����"></FONT></td>
	</tr>
	<TR>
		<TD style="WIDTH: 76px; HEIGHT: 20px"><FONT face="�����w">����</FONT></TD>
		<TD style="WIDTH: 136px; HEIGHT: 20px">
			<asp:TextBox id="tbgold" runat="server" MaxLength="14" Width="88px"></asp:TextBox></TD>
		<TD style="HEIGHT: 20px">
			<asp:RequiredFieldValidator id="RequiredFieldValidator1" runat="server" ControlToValidate="tbgold" ErrorMessage="*"></asp:RequiredFieldValidator>Ոݔ����Ҫ���Q�Ľ��Ŕ���</TD>
	</TR>
	<TR>
		<TD align="center" colSpan="3" height="10"><FONT face="����"></FONT></TD>
	</TR>
	<TR>
		<TD colspan="3" align="center">
			<asp:Button id="btnchange" runat="server" Text="ُ�I�[���" CssClass="button_1"></asp:Button>
		</TD>
	</TR>
</table>
<asp:RegularExpressionValidator id="RegularExpressionValidator1" runat="server" ErrorMessage="Ո�������" ValidationExpression="^\+?[1-9][0-9]*$"
	ControlToValidate="tbgold"></asp:RegularExpressionValidator>
