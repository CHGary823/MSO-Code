<%@ Control Language="c#" AutoEventWireup="false" Codebehind="resetpoint.ascx.cs" Inherits="web.control.resetpoint" TargetSchema="http://schemas.microsoft.com/intellisense/ie5"%>
<table cellspacing="1" cellpadding="1" width="520" border="0" style="WIDTH: 520px; HEIGHT: 228px">
	<TR>
		<TD colspan="3">
			<P><b>�ھ�ϴ�c:</b></P>
			<P>�ھ�ϴ�c��Ҫ�˳��[��</P>
			<p>ϴ�c��Ҫ����<b><font color="#ff3333"><%=Application["game.resetpointgold"]%></font>��</b>,�[���<b><font color="#ff3333"><%=Application["game.resetpointmoney"]%></font>Ԫ</b></p>
			<P>ע�⣺15�D���ϵ����ϴ�c�����D�D�������ԄӼ����w�|�����wՈ�����D��ע�����</P>
		</TD>
	</TR>
	<tr>
		<td style="WIDTH: 103px">��ꑎ�̖</td>
		<td style="WIDTH: 120px"><strong><%=Session["userid"]%></strong></td>
		<td><FONT face="����"></FONT></td>
	</tr>
	<tr>
		<td style="WIDTH: 103px; HEIGHT: 18px">��ɫ�б�</td>
		<td style="WIDTH: 120px; HEIGHT: 18px">
			<asp:DropDownList id="ddchalist" runat="server"></asp:DropDownList></td>
		<td style="HEIGHT: 18px">
			<asp:RequiredFieldValidator id="Requiredfieldvalidator6" runat="server" ErrorMessage="*" ControlToValidate="ddchalist"></asp:RequiredFieldValidator>Ո�x����Ҫϴ�c�Ľ�ɫ</td>
	</tr>
	<TR>
		<TD align="center" colSpan="3" height="10"><FONT face="����"></FONT></TD>
	</TR>
	<TR>
		<TD colspan="3" align="center">
			<asp:Button id="btnreset" runat="server" Text="�_�Jϴ�c" CssClass="button_1"></asp:Button>
		</TD>
	</TR>
</table>
