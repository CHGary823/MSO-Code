<%@ Control Language="c#" AutoEventWireup="false" Codebehind="addpoint.ascx.cs" Inherits="web.control.addpoint" TargetSchema="http://schemas.microsoft.com/intellisense/ie5"%>
<table cellspacing="1" cellpadding="1" width="528" border="0">
	<TR>
		<TD colspan="3">
			<P><b>�ھ����c����:</b></P>
			<P>�ھ����c��Ҫ�˳��[��</P>
			<p>��������ȫ���M���p�p��ҵļ��cؓ�������o��ָ������؟^^</p>
			<P>&nbsp;</P>
		</TD>
	</TR>
	<tr>
		<td style="WIDTH: 150px">��ꑎ�̖</td>
		<td style="WIDTH: 119px"><strong><%=Session["userid"]%></strong></td>
		<td><FONT face="����"></FONT></td>
	</tr>
	<tr>
		<td style="WIDTH: 150px; HEIGHT: 20px">��ɫ�б�</td>
		<td style="WIDTH: 119px; HEIGHT: 20px">
			<asp:DropDownList id="ddchalist" runat="server" AutoPostBack="True"></asp:DropDownList></td>
		<td style="HEIGHT: 20px">
			<asp:RequiredFieldValidator id="Requiredfieldvalidator6" runat="server" ErrorMessage="*" ControlToValidate="ddchalist"></asp:RequiredFieldValidator>Ո�x����Ҫ���c�Ľ�ɫ</td>
	</tr>
	<TR>
		<TD style="WIDTH: 150px; HEIGHT: 20px">����[�F��
			<asp:Label id="lblgengoal" runat="server"></asp:Label>]</TD>
		<TD style="WIDTH: 119px; HEIGHT: 20px">
			<asp:TextBox id="tbgengoal" runat="server" Width="87px"></asp:TextBox></TD>
		<TD style="HEIGHT: 20px">
			<asp:RequiredFieldValidator id="RequiredFieldValidator1" runat="server" ControlToValidate="tbgengoal" ErrorMessage="*"></asp:RequiredFieldValidator></TD>
	</TR>
	<TR>
		<TD style="WIDTH: 150px; HEIGHT: 20px">����[�F��
			<asp:Label id="lbldex" runat="server"></asp:Label>]</TD>
		<TD style="WIDTH: 119px; HEIGHT: 20px">
			<asp:TextBox id="tbdex" runat="server" Width="87px"></asp:TextBox></TD>
		<TD style="HEIGHT: 20px">
			<asp:RequiredFieldValidator id="Requiredfieldvalidator2" runat="server" ControlToValidate="tbdex" ErrorMessage="*"></asp:RequiredFieldValidator></TD>
	</TR>
	<TR>
		<TD style="WIDTH: 150px; HEIGHT: 20px">�w�|[�F��
			<asp:Label id="lblsta" runat="server"></asp:Label>]</TD>
		<TD style="WIDTH: 119px; HEIGHT: 20px">
			<asp:TextBox id="tbsta" runat="server" Width="87px"></asp:TextBox></TD>
		<TD style="HEIGHT: 20px">
			<asp:RequiredFieldValidator id="Requiredfieldvalidator3" runat="server" ControlToValidate="tbsta" ErrorMessage="*"></asp:RequiredFieldValidator></TD>
	</TR>
	<TR>
		<TD style="WIDTH: 150px; HEIGHT: 20px">����[�F��
			<asp:Label id="lblsimmak" runat="server"></asp:Label>]</TD>
		<TD style="WIDTH: 119px; HEIGHT: 20px">
			<asp:TextBox id="tbsimmak" runat="server" Width="87px"></asp:TextBox></TD>
		<TD style="HEIGHT: 20px">
			<asp:RequiredFieldValidator id="Requiredfieldvalidator4" runat="server" ControlToValidate="tbsimmak" ErrorMessage="*"></asp:RequiredFieldValidator></TD>
	</TR>
	<TR>
		<TD style="WIDTH: 150px; HEIGHT: 20px">ʣ�N�c��</TD>
		<TD style="WIDTH: 119px; HEIGHT: 20px"><FONT face="����">
				<asp:Label id="lblpoint" runat="server"></asp:Label></FONT></TD>
		<TD style="HEIGHT: 20px"><FONT face="����"></FONT></TD>
	</TR>
	<TR>
		<TD align="center" colSpan="3" height="10"><FONT face="����"></FONT></TD>
	</TR>
	<TR>
		<TD colspan="3" align="center">
			<asp:Button id="btnadd" runat="server" Text="�ھ����c" CssClass="button_1"></asp:Button>
		</TD>
	</TR>
</table>
<asp:RegularExpressionValidator id="RegularExpressionValidator1" runat="server" ErrorMessage="Ոݔ������ӵ������c" ValidationExpression="^\d{1,5}$"
	ControlToValidate="tbgengoal"></asp:RegularExpressionValidator><br>
<asp:RegularExpressionValidator id="Regularexpressionvalidator2" runat="server" ErrorMessage="Ոݔ������ӵ������c" ValidationExpression="^\d{1,5}$"
	ControlToValidate="tbdex"></asp:RegularExpressionValidator><br>
<asp:RegularExpressionValidator id="Regularexpressionvalidator3" runat="server" ErrorMessage="Ոݔ������ӵ��w�|�c" ValidationExpression="^\d{1,5}$"
	ControlToValidate="tbsta"></asp:RegularExpressionValidator><br>
<asp:RegularExpressionValidator id="Regularexpressionvalidator4" runat="server" ErrorMessage="Ոݔ������ӵ����}�c" ValidationExpression="^\d{1,5}$"
	ControlToValidate="tbsimmak"></asp:RegularExpressionValidator><br>
