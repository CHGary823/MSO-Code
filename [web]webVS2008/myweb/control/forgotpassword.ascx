<%@ Control Language="c#" AutoEventWireup="false" Codebehind="forgotpassword.ascx.cs" Inherits="web.control.forgotpassword" TargetSchema="http://schemas.microsoft.com/intellisense/ie5"%>
<table cellspacing="1" cellpadding="1" width="60%" border="0">
	<TR>
		<TD colspan="3"><b>�һص���ܴa</b></TD>
	</TR>
	<tr>
		<td>��ꑎ�̖</td>
		<td>
			<asp:TextBox id="tbuserid" runat="server"></asp:TextBox></td>
		<td>
			<asp:RequiredFieldValidator id="RequiredFieldValidator1" runat="server" ErrorMessage="*" ControlToValidate="tbuserid"></asp:RequiredFieldValidator>�H��4~12λa-z,A-Z��ĸ������</td>
	</tr>
	<tr>
		<td>�����ܴa</td>
		<td>
			<asp:TextBox id="tbkey" runat="server" TextMode="Password"></asp:TextBox></td>
		<td>
			<asp:RequiredFieldValidator id="Requiredfieldvalidator6" runat="server" ErrorMessage="*" ControlToValidate="tbkey"></asp:RequiredFieldValidator>�H��4~12λa-z,A-Z��ĸ������</td>
	</tr>
	<tr>
		<td>����]��</td>
		<td>
			<asp:TextBox id="tbemail" runat="server"></asp:TextBox></td>
		<td>
			<asp:RequiredFieldValidator id="RequiredFieldValidator2" runat="server" ErrorMessage="*" ControlToValidate="tbemail"></asp:RequiredFieldValidator></td>
	</tr>
	<TR>
		<TD style="WIDTH: 84px">��C�a</TD>
		<TD style="WIDTH: 151px">
			<asp:TextBox id="tbverifycode" runat="server" MaxLength="4" Columns="4"></asp:TextBox><IMG id="imgVerify" style="WIDTH: 56px; CURSOR: hand; HEIGHT: 20px" onclick="this.src=this.src"
				height="20" alt="�����壿�c�����Q" src="./VerifyCode.aspx" width="56"></TD>
		<TD>
			<asp:RequiredFieldValidator id="Requiredfieldvalidator5" runat="server" ErrorMessage="*" ControlToValidate="tbverifycode"></asp:RequiredFieldValidator>Ոݔ��DƬ�е���λ����</TD>
	</TR>
	<TR>
		<TD style="HEIGHT: 21px" align="center" colSpan="3"></TD>
	</TR>
	<TR>
		<TD align="center" colSpan="3" style="HEIGHT: 21px">��ʾ���ܴa�һ��ጢ���޸Ğ�123456,Ո�ٵ�ꑾWվ���޸�</TD>
	</TR>
	<TR>
		<TD align="center" colSpan="3"><FONT face="�����w"></FONT></TD>
	</TR>
	<TR>
		<TD colspan="3" align="center">
			<asp:Button id="btnreset" runat="server" Text="�һ��ܴa" CssClass="button_1"></asp:Button>
		</TD>
	</TR>
</table>
<asp:RegularExpressionValidator id="RegularExpressionValidator1" runat="server" ErrorMessage="��̖��ʽ�e�`!" ControlToValidate="tbuserid"
	ValidationExpression="^[A-Za-z0-9]{4,12}$"></asp:RegularExpressionValidator><br>
<asp:RegularExpressionValidator id="RegularExpressionValidator2" runat="server" ErrorMessage="�����ܴa��ʽ�e�`!" ControlToValidate="tbkey"
	ValidationExpression="^[A-Za-z0-9]{4,12}$"></asp:RegularExpressionValidator><br>
<asp:RegularExpressionValidator id="RegularExpressionValidator3" runat="server" ControlToValidate="tbemail" ErrorMessage="�]���ʽ�e�`!"
	ValidationExpression="\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*"></asp:RegularExpressionValidator><BR>
<asp:RegularExpressionValidator id="RegularExpressionValidator6" runat="server" ControlToValidate="tbverifycode"
	ErrorMessage="��C�a��ʽ�e�`!" ValidationExpression="\d{4}$"></asp:RegularExpressionValidator><BR>
