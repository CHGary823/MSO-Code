<%@ Control Language="c#" AutoEventWireup="false" Codebehind="petlevelup.ascx.cs" Inherits="web.control.petlevelup" TargetSchema="http://schemas.microsoft.com/intellisense/ie5"%>
<table cellspacing="1" cellpadding="1" width="528" border="0">
	<TR>
		<TD colspan="3" style="HEIGHT: 290px">
			<P><b>��������:</b></P>
			<P>���������r�����Ҫ�˳��[�򣬌�����߿�������<FONT color="#0000ff"><B>3</B></FONT>����</P>
			<P>1.һ������������������Ҫ����<span style="FONT-WEIGHT:bold;COLOR:#ff3333"><%=Application["game.petlvupgold2"]%></span></P>
			<P>2.��������������������Ҫ����<span style="FONT-WEIGHT:bold;COLOR:#ff3333"><%=Application["game.petlvupgold3"]%></span></P>
			<P>�f��:�����ɹ��ʞ�<FONT color="#0000ff"><STRONG>100%</STRONG></FONT><FONT color="#000000">,�����ጙ����H�ܶȞ�<FONT color="#0000ff"><STRONG>30</STRONG></FONT></FONT></P>
		</TD>
	</TR>
	<tr>
		<td style="WIDTH: 103px">��ꑎ�̖</td>
		<td style="WIDTH: 120px"><strong><%=Session["userid"]%></strong></td>
		<td><FONT face="����"></FONT></td>
	</tr>
	<tr>
		<td style="WIDTH: 103px; HEIGHT: 14px">�����б�</td>
		<td style="WIDTH: 120px; HEIGHT: 14px">
			<asp:DropDownList id="ddpetlist" runat="server"></asp:DropDownList></td>
		<td style="HEIGHT: 14px">
			<asp:RequiredFieldValidator id="Requiredfieldvalidator6" runat="server" ErrorMessage="*" ControlToValidate="ddpetlist"></asp:RequiredFieldValidator>Ո�x����Ҫ�����Č���</td>
	</tr>
	<TR>
		<TD align="center" colSpan="3" height="10"><FONT face="����"></FONT></TD>
	</TR>
	<TR>
		<TD colspan="3" align="center">
			<asp:Button id="btnedit" runat="server" Text="�_�J����" CssClass="button_1"></asp:Button>
		</TD>
	</TR>
</table>
