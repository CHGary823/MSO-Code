<%@ Control Language="c#" AutoEventWireup="false" Codebehind="bank.ascx.cs" Inherits="web.control.bank" TargetSchema="http://schemas.microsoft.com/intellisense/ie5"%>
<table cellspacing="1" cellpadding="1" width="528" border="0">
	<TR>
		<TD colspan="3">
			<P><b>�W���y��:</b></P>
			<P>��춂}��ĿɷŽ��X����̫С�����@�e���Ԍ�����ɫ�ϵĽ��Xȫ�������y��Ŷ���y�О鎤̖��ʽ��ͬһ��̖���н�ɫ�������ڴ˴��Xȡ�X�����X���ޞ�5000�|��ȡ�X���ޞ���Ͻ�ɫ�Ԏ��Ĺ�20�|</P>
			<P><FONT face="����"></FONT>&nbsp;</P>
		</TD>
	</TR>
	<tr>
		<td style="WIDTH: 103px">��ꑎ�̖</td>
		<td style="WIDTH: 88px"><strong><span style="FONT-WEIGHT:bold;COLOR:#5d51f1"><%=Session["userid"]%></span></strong></td>
		<td></td>
	</tr>
	<tr>
		<td style="WIDTH: 103px">�y�д��</td>
		<td style="WIDTH: 88px"><strong><span style="FONT-WEIGHT:bold;COLOR:#ff3333"><%=webbank%></span>/<strong><span style="FONT-WEIGHT:bold;COLOR:#5d51f1">500000000000</span></strong></strong></td>
		<td><FONT face="����">���@ʾ�e�`Ո�ص�ꑾWվ</FONT></td>
	</tr>
	<tr>
		<td style="WIDTH: 103px; HEIGHT: 20px">��ɫ�б�</td>
		<td style="WIDTH: 88px; HEIGHT: 20px">
			<asp:DropDownList id="ddchalist" runat="server"></asp:DropDownList></td>
		<td style="HEIGHT: 20px">
			<asp:RequiredFieldValidator id="Requiredfieldvalidator6" runat="server" ErrorMessage="*" ControlToValidate="ddchalist"></asp:RequiredFieldValidator>Ո�x����Ҫ�����Ľ�ɫ</td>
	</tr>
	<TR>
		<TD style="WIDTH: 103px; HEIGHT: 20px">ݔ����~</TD>
		<TD style="WIDTH: 88px; HEIGHT: 20px">
			<asp:TextBox id="tbmoney" runat="server" MaxLength="14" Width="169px"></asp:TextBox></TD>
		<TD style="HEIGHT: 20px">
			<asp:RequiredFieldValidator id="RequiredFieldValidator1" runat="server" ControlToValidate="tbmoney" ErrorMessage="*"></asp:RequiredFieldValidator>Ոݔ���/ȡ���~</TD>
	</TR>
	<TR>
		<TD align="center" colSpan="3" height="10">
			<asp:RadioButton id="rbput" runat="server" Text="���X���y��" GroupName="bank" Checked="True"></asp:RadioButton>
			<asp:RadioButton id="rbget" runat="server" Text="ȡ�X����ɫ" GroupName="bank"></asp:RadioButton></TD>
	</TR>
	<TR>
		<TD colspan="3" align="center">
			<asp:Button id="btnedit" runat="server" Text="�y�в���" CssClass="button_1"></asp:Button>
		</TD>
	</TR>
</table>
<P>
	<asp:RegularExpressionValidator id="RegularExpressionValidator1" runat="server" ErrorMessage="���X��ʽ����" ValidationExpression="^\d{1,10}$"
		ControlToValidate="tbmoney"></asp:RegularExpressionValidator><br>
<P></P>
