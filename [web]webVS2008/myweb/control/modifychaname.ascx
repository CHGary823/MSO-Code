<%@ Control Language="c#" AutoEventWireup="false" Codebehind="modifychaname.ascx.cs" Inherits="web.control.modifychaname" TargetSchema="http://schemas.microsoft.com/intellisense/ie5"%>
<table cellspacing="1" cellpadding="1" width="528" border="0">
	<TR>
		<TD colspan="3">
			<P><b>��ɫ����:</b></P>
			<P>������Ҫ�˳��[�������Ը�<span style="FONT-WEIGHT:bold;COLOR:#5D51F1"><%=Application["game.modifychanamecount"]%></span>���� ע��������ʹ��^%&amp;',;=?$\���ַ�</P>
			<p>ÿ�θ�����Ҫ���M�[���<span style="FONT-WEIGHT:bold;COLOR:#FF3333"><%=Application["game.modifychanamemoney"]%></span>Ԫ��Ո���X����Ʒ���ف����</p>
		</TD>
	</TR>
	<tr>
		<td style="WIDTH: 103px">��ꑎ�̖</td>
		<td style="WIDTH: 120px"><strong><%=Session["userid"]%></strong></td>
		<td></td>
	</tr>
	<tr>
		<td style="WIDTH: 103px; HEIGHT: 20px">��ɫ�б�</td>
		<td style="WIDTH: 120px; HEIGHT: 20px">
			<asp:DropDownList id="ddchalist" runat="server"></asp:DropDownList></td>
		<td style="HEIGHT: 20px">
			<asp:RequiredFieldValidator id="Requiredfieldvalidator6" runat="server" ErrorMessage="*" ControlToValidate="ddchalist"></asp:RequiredFieldValidator>Ո�x����Ҫ�����Ľ�ɫ</td>
	</tr>
	<TR>
		<TD style="WIDTH: 103px; HEIGHT: 20px"><FONT face="�����w">�½�ɫ��</FONT></TD>
		<TD style="WIDTH: 120px; HEIGHT: 20px">
			<asp:TextBox id="tbnewname" runat="server" MaxLength="14" Width="145px"></asp:TextBox></TD>
		<TD style="HEIGHT: 20px">
				<asp:RequiredFieldValidator id="RequiredFieldValidator1" runat="server" ControlToValidate="tbnewname" ErrorMessage="*"></asp:RequiredFieldValidator>Ոݔ���½�ɫ��</FONT></TD>
	</TR>
	<TR>
		<TD align="center" colSpan="3" height="10"></TD>
	</TR>
	<TR>
		<TD colspan="3" align="center">
			<asp:Button id="btnedit" runat="server" Text="�޸Ľ�ɫ���Q" CssClass="button_1"></asp:Button>
		</TD>
	</TR>
</table>
<asp:RegularExpressionValidator id="RegularExpressionValidator1" runat="server" ErrorMessage="��ɫ����ʽ�����_" ValidationExpression="^[^%&amp;',;=?$\x22]+"
	ControlToValidate="tbnewname"></asp:RegularExpressionValidator>
