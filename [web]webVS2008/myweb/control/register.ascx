<%@ Control Language="c#" AutoEventWireup="false" Codebehind="register.ascx.cs" Inherits="web.control.register" TargetSchema="http://schemas.microsoft.com/intellisense/ie5"%>
<table id="Table1" cellSpacing="1" cellPadding="1" width="512" border="0" style="WIDTH: 512px; HEIGHT: 348px">
	<TR align="left">
		<TD colSpan="3"><strong>�[��̖�]��</strong></TD>
	</TR>
	<tr>
		<td>��ꑎ�̖</td>
		<td><asp:textbox id="tbuserid" runat="server"></asp:textbox></td>
		<td align="left"><asp:requiredfieldvalidator id="RequiredFieldValidator1" runat="server" ControlToValidate="tbuserid" ErrorMessage="*"></asp:requiredfieldvalidator>�H��4~12λa-z,A-Z��ĸ������</td>
	</tr>
	<TR>
		<TD class="red" colSpan="3">ע�⣺�������Ď�̖��ȫ��ݔ��Ď�̖Ո��Ҫ�cՓ����̖���[���н�ɫ����ͬ</TD>
	</TR>
	<tr>
		<td style="HEIGHT: 26px">�ܴa</td>
		<td style="HEIGHT: 26px"><asp:textbox id="tbuserpwd" runat="server" TextMode="Password"></asp:textbox></td>
		<td align="left" style="HEIGHT: 26px"><asp:requiredfieldvalidator id="RequiredFieldValidator2" runat="server" ControlToValidate="tbuserpwd" ErrorMessage="*"></asp:requiredfieldvalidator>�H��4~12λa-z,A-Z��ĸ������</td>
	</tr>
	<tr>
		<td>�_�J�ܴa</td>
		<td><asp:textbox id="tbreuserpwd" runat="server" TextMode="Password"></asp:textbox></td>
		<td align="left">�H��4~12λa-z,A-Z��ĸ������</td>
	</tr>
	<TR>
		<TD>�Ԅe</TD>
		<TD><asp:radiobutton id="rbmale" runat="server" Checked="True" Text="��" GroupName="reg"></asp:radiobutton><asp:radiobutton id="rbfemale" runat="server" Text="Ů" GroupName="reg"></asp:radiobutton></TD>
		<TD align="left">Ո�x���Ԅe</TD>
	</TR>
	<TR>
		<TD>����]��</TD>
		<TD><asp:textbox id="tbemail" runat="server"></asp:textbox></TD>
		<TD align="left"><asp:requiredfieldvalidator id="RequiredFieldValidator3" runat="server" ControlToValidate="tbemail" ErrorMessage="*"></asp:requiredfieldvalidator>Ոݔ���]���ַ</TD>
	</TR>
	<TR>
		<TD>�����ܴa</TD>
		<TD align="left"><asp:textbox id="tbkey" runat="server" TextMode="Password"></asp:textbox></TD>
		<TD align="left"><asp:requiredfieldvalidator id="Requiredfieldvalidator4" runat="server" ControlToValidate="tbkey" ErrorMessage="*"
				Display="Dynamic"></asp:requiredfieldvalidator>�H��4~12λa-z,A-Z��ĸ������
		</TD>
	</TR>
	<TR>
		<TD class="red" colSpan="3">ע�⣺�����ܴa�����c��ꑎ�̖�����ܴaһ�ӣ��������һ��ܴa��Ψһ����</TD>
	</TR>
	<TR>
		<TD style="HEIGHT: 15px">���]��</TD>
		<TD style="HEIGHT: 15px"><asp:textbox id="tbcommend" runat="server" Columns="10" BackColor="#E0E0E0" ReadOnly="True"></asp:textbox></TD>
		<TD align="left" style="HEIGHT: 15px">�]�����]��Ո����</TD>
	</TR>
	<TR>
		<TD>��C�a</TD>
		<TD><asp:textbox id="tbverifycode" runat="server" Columns="4" MaxLength="4"></asp:textbox><IMG id="imgVerify" style="WIDTH: 56px; CURSOR: hand; HEIGHT: 20px" onclick="this.src=this.src"
				height="20" alt="�����壿�c�����Q" src="./VerifyCode.aspx" width="56"></TD>
		<TD><asp:requiredfieldvalidator id="Requiredfieldvalidator5" runat="server" ControlToValidate="tbverifycode" ErrorMessage="*"></asp:requiredfieldvalidator>Ոݔ��DƬ�е���λ����</TD>
	</TR>
	<TR>
		<TD align="center" colSpan="3" height="5"></TD>
	</TR>
	<TR>
		<TD align="center" colSpan="3"><A class="red" href="agreement.aspx" target="_blank">�_�J�]�Ա�ʾ���ѽ��м���x�ˡ��Ñ�f�h��</A></TD>
	</TR>
	<TR>
		<TD align="center" colSpan="3" height="5"></TD>
	</TR>
	<TR>
		<TD align="center" colSpan="3"><asp:button id="btnregister" runat="server" Text="ע  ��" CssClass="button_1"></asp:button></TD>
	</TR>
</table>
<P><asp:regularexpressionvalidator id="RegularExpressionValidator1" runat="server" ControlToValidate="tbuserid" ErrorMessage="��̖��ʽ�e�`!"
		ValidationExpression="^[A-Za-z0-9]{4,12}$"></asp:regularexpressionvalidator><br>
	<asp:regularexpressionvalidator id="RegularExpressionValidator2" runat="server" ControlToValidate="tbuserpwd" ErrorMessage="�ܴa��ʽ�e�`!"
		ValidationExpression="^[A-Za-z0-9]{4,12}$"></asp:regularexpressionvalidator><br>
	<asp:comparevalidator id="CompareValidator1" runat="server" ControlToValidate="tbreuserpwd" ErrorMessage="�ɴ��ܴa��һ��!"
		ControlToCompare="tbuserpwd"></asp:comparevalidator><br>
	<asp:RegularExpressionValidator id="RegularExpressionValidator7" runat="server" ControlToValidate="tbemail" ErrorMessage="�]���ʽ�e�`!"
		ValidationExpression="\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*"></asp:RegularExpressionValidator><br>
	<asp:RegularExpressionValidator id="RegularExpressionValidator4" runat="server" ErrorMessage="�����ܴa��ʽ�e�`!" ControlToValidate="tbkey"
		ValidationExpression="^[A-Za-z0-9]{4,12}$"></asp:RegularExpressionValidator><br>
	<asp:RegularExpressionValidator id="RegularExpressionValidator6" runat="server" ErrorMessage="��C�a��ʽ�e�`!" ControlToValidate="tbverifycode"
		ValidationExpression="\d{4}$"></asp:RegularExpressionValidator><br>
	<asp:RegularExpressionValidator id="RegularExpressionValidator5" runat="server" ErrorMessage="���]�˸�ʽ�e�`!" ControlToValidate="tbcommend"
		ValidationExpression="^[A-Za-z0-9]{4,12}$"></asp:RegularExpressionValidator><br>
</P>
