<%@ Control Language="c#" AutoEventWireup="false" Codebehind="skilllevelup.ascx.cs" Inherits="web.control.skilllevelup" TargetSchema="http://schemas.microsoft.com/intellisense/ie5"%>
<table cellspacing="1" cellpadding="1" width="528" border="0">
	<TR>
		<TD colspan="3">
			<P><b>�����书��ꇷ�:</b></P>
			<P>�����书��ꇷ���Ҫ�˳��[��</P>
			<p>ÿ��һ���书��ꇷ���Ҫ�[���<b><font color="#ff3333"><%=Application["game.skilllvupmoney"]%></font></b>,��߿�������12��</p>
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
			<asp:DropDownList id="ddchalist" runat="server" AutoPostBack="True"></asp:DropDownList></td>
		<td style="HEIGHT: 20px">
			<asp:RequiredFieldValidator id="Requiredfieldvalidator6" runat="server" ErrorMessage="*" ControlToValidate="ddchalist"></asp:RequiredFieldValidator>Ո�x����Ҫ�����书�Ľ�ɫ</td>
	</tr>
	<TR>
		<TD style="WIDTH: 103px; HEIGHT: 20px">�书��ꇷ�</TD>
		<TD style="WIDTH: 136px; HEIGHT: 20px">
			<asp:DropDownList id="ddmugong" runat="server"></asp:DropDownList></TD>
		<TD style="HEIGHT: 20px">
			<asp:RequiredFieldValidator id="RequiredFieldValidator1" runat="server" ControlToValidate="ddmugong" ErrorMessage="*"></asp:RequiredFieldValidator>Ո�x����Ҫ�������书���Q</TD>
	</TR>
	<TR>
		<TD align="center" colSpan="3" height="10"><FONT face="����"></FONT></TD>
	</TR>
	<TR>
		<TD colspan="3" align="center">
			<asp:Button id="btnlvup" runat="server" Text="�ޟ��书" CssClass="button_1"></asp:Button>
		</TD>
	</TR>
</table>
