<%@ Control Language="c#" AutoEventWireup="false" Codebehind="modifypassword.ascx.cs" Inherits="web.control.modifypassword" TargetSchema="http://schemas.microsoft.com/intellisense/ie5"%>
<table cellspacing="1" cellpadding="1" width="60%" border="0">
	<TR>
		<TD colspan="3"><b>�޸ĵ���ܴa</b></TD>
	</TR>
	<tr>
		<td style="WIDTH: 84px">��ꑎ�̖</td>
		<td style="WIDTH: 151px">
			<asp:TextBox id="tbuserid" runat="server"></asp:TextBox></td>
		<td>
			<asp:RequiredFieldValidator id="RequiredFieldValidator1" runat="server" ErrorMessage="*" ControlToValidate="tbuserid"></asp:RequiredFieldValidator>�H��4~12λa-z,A-Z��ĸ������</td>
	</tr>
	<tr>
		<td style="WIDTH: 84px">�f�ܴa</td>
		<td style="WIDTH: 151px">
			<asp:TextBox id="tbolduserpwd" runat="server" TextMode="Password"></asp:TextBox></td>
		<td>
			<asp:RequiredFieldValidator id="Requiredfieldvalidator6" runat="server" ErrorMessage="*" ControlToValidate="tbolduserpwd"></asp:RequiredFieldValidator>�H��4~12λa-z,A-Z��ĸ������</td>
	</tr>
	<tr>
		<td style="WIDTH: 84px">���ܴa</td>
		<td style="WIDTH: 151px">
			<asp:TextBox id="tbnewuserpwd" runat="server" TextMode="Password"></asp:TextBox></td>
		<td>
			<asp:RequiredFieldValidator id="RequiredFieldValidator2" runat="server" ErrorMessage="*" ControlToValidate="tbnewuserpwd"></asp:RequiredFieldValidator>�H��4~12λa-z,A-Z��ĸ������</td>
	</tr>
	<tr>
		<td style="WIDTH: 84px">�_�J���ܴa</td>
		<td style="WIDTH: 151px">
			<asp:TextBox id="tbrenewuserpwd" runat="server" TextMode="Password"></asp:TextBox></td>
		<td>�H��4~12λa-z,A-Z��ĸ������</td>
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
		<TD align="center" colSpan="3" height="10"><FONT face="�����w"></FONT></TD>
	</TR>
	<TR>
		<TD colspan="3" align="center">
			<asp:Button id="btnmodify" runat="server" Text="�޸��ܴa" CssClass="button_1"></asp:Button>
		</TD>
	</TR>
</table>
<asp:RegularExpressionValidator id="RegularExpressionValidator1" runat="server" ErrorMessage="��̖��ʽ�e�`!" ControlToValidate="tbuserid"
	ValidationExpression="^[A-Za-z0-9]{4,12}$"></asp:RegularExpressionValidator><br>
<asp:RegularExpressionValidator id="RegularExpressionValidator2" runat="server" ErrorMessage="�f�ܴa��ʽ�e�`!" ControlToValidate="tbolduserpwd"
	ValidationExpression="^[A-Za-z0-9]{4,12}$"></asp:RegularExpressionValidator><br>
<asp:RegularExpressionValidator id="RegularExpressionValidator4" runat="server" ControlToValidate="tbnewuserpwd"
	ErrorMessage="���ܴa��ʽ�e�`!" ValidationExpression="^[A-Za-z0-9]{4,12}$"></asp:RegularExpressionValidator><BR>
<asp:CompareValidator id="CompareValidator1" runat="server" ErrorMessage="�ɴ��ܴa��һ��!" ControlToValidate="tbrenewuserpwd"
	ControlToCompare="tbnewuserpwd"></asp:CompareValidator><BR>
<asp:RegularExpressionValidator id="RegularExpressionValidator6" runat="server" ControlToValidate="tbverifycode"
	ErrorMessage="��C�a��ʽ�e�`!" ValidationExpression="\d{4}$"></asp:RegularExpressionValidator>
