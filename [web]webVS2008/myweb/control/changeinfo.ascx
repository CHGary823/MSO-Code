<%@ Control Language="c#" AutoEventWireup="false" Codebehind="changeinfo.ascx.cs" Inherits="web.control.changeinfo" TargetSchema="http://schemas.microsoft.com/intellisense/ie5"%>
<table cellspacing="1" cellpadding="1" width="60%" border="0">
	<TR>
		<TD colspan="3"><b>�޸Ķ����ܴa�cEMAIL</b></TD>
	</TR>
	<TR>
		<TD colSpan="3">
			<P><FONT face="����">�����ܱ��o��ҵ��~��,�޸Ķ����ܴa�cEMAIL��Ҫ<%=Application["game.changeinfogold"]%>����</FONT></P>
		</TD>
	</TR>
	<tr>
		<td>��ꑎ�̖</td>
		<td>
			<asp:TextBox id="tbuserid" runat="server" ReadOnly="True" ForeColor="White" BackColor="#E0E0E0"></asp:TextBox></td>
		<td><FONT face="����"></FONT></td>
	</tr>
	<tr>
		<td>�¶����ܴa</td>
		<td>
			<asp:TextBox id="tbkey" runat="server" TextMode="Password" Height="24px"></asp:TextBox></td>
		<td>
			<asp:RequiredFieldValidator id="Requiredfieldvalidator6" runat="server" ErrorMessage="*" ControlToValidate="tbkey"></asp:RequiredFieldValidator>�H��4~12λa-z,A-Z��ĸ������</td>
	</tr>
	<tr>
		<td>�_�J�¶����ܴa</td>
		<td>
			<asp:TextBox id="tbrekey" runat="server" TextMode="Password" Height="24px"></asp:TextBox></td>
		<td>
			<asp:RequiredFieldValidator id="Requiredfieldvalidator1" runat="server" ErrorMessage="*" ControlToValidate="tbkey"></asp:RequiredFieldValidator>�H��4~12λa-z,A-Z��ĸ������</td>
	</tr>
	<tr>
		<td>������]��EMAIL</td>
		<td>
			<asp:TextBox id="tbemail" runat="server"></asp:TextBox></td>
		<td>
			<asp:RequiredFieldValidator id="RequiredFieldValidator2" runat="server" ErrorMessage="*" ControlToValidate="tbemail"></asp:RequiredFieldValidator></td>
	</tr>
	<tr>
		<td>�_�J������]��EMAIL</td>
		<td>
			<asp:TextBox id="tbreemail" runat="server"></asp:TextBox></td>
		<td>
			<asp:RequiredFieldValidator id="Requiredfieldvalidator3" runat="server" ErrorMessage="*" ControlToValidate="tbemail"></asp:RequiredFieldValidator></td>
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
		<TD align="center" colSpan="3"><FONT face="�����w"></FONT></TD>
	</TR>
	<TR>
		<TD colspan="3" align="center">
			<asp:Button id="btnedit" runat="server" Text="�_�J�޸Ķ����ܴa�cEMAIL" CssClass="button_1"></asp:Button>
		</TD>
	</TR>
</table>
<br>
<asp:RegularExpressionValidator id="RegularExpressionValidator2" runat="server" ErrorMessage="�����ܴa��ʽ�e�`!" ControlToValidate="tbkey"
	ValidationExpression="^[A-Za-z0-9]{4,12}$"></asp:RegularExpressionValidator><br>
<asp:RegularExpressionValidator id="RegularExpressionValidator3" runat="server" ControlToValidate="tbemail" ErrorMessage="�]���ʽ�e�`!"
	ValidationExpression="\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*"></asp:RegularExpressionValidator><BR>
<asp:RegularExpressionValidator id="RegularExpressionValidator6" runat="server" ControlToValidate="tbverifycode"
	ErrorMessage="��C�a��ʽ�e�`!" ValidationExpression="\d{4}$"></asp:RegularExpressionValidator><BR>
<asp:CompareValidator id="CompareValidator1" runat="server" ControlToValidate="tbreemail" ErrorMessage="�ɴ�EMAILݔ�벻һ��"
	ControlToCompare="tbemail"></asp:CompareValidator><br>
<asp:CompareValidator id="CompareValidator2" runat="server" ControlToValidate="tbrekey" ErrorMessage="�ɴζ����ܴaݔ�벻һ��"
	ControlToCompare="tbkey"></asp:CompareValidator>
