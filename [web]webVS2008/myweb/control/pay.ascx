<%@ Control Language="c#" AutoEventWireup="false" Codebehind="pay.ascx.cs" Inherits="web.control.pay" TargetSchema="http://schemas.microsoft.com/intellisense/ie5"%>
<table cellspacing="1" cellpadding="1" width="528" border="0">
	<TR>
		<TD colspan="3">
			<P><b>������ُ�I����:</b></P>
			<P>��ꑵ؅^�ھ���ֵϵ�y��֧���ɹ��ᣬ���Ō��Ԅӳ�����Ҏ�����Ո��ֵ�����е�ꑾWվ��ԃ���ǳ����㡣</P>
			<P>Ո�ձ�ӛ�����ӆ��̖��������r�¿��Ը���ӆ��̖��GM̎��ԃ</P>
			<P><FONT face="����" color="#cc3366"><b>��Ҫ��ʾ��</b></FONT></P>
			<P><FONT face="����" color="#cc3366"><B>1.Ո���P��3721���������P�]�������ڵĲ��</B></FONT></P>
			<P><FONT face="����" color="#cc3366"><B>2.Ո���Ї���ꑵ؅^����Ҳ�Ҫ�c����ӆ�Σ��Ǵ�ꑵ؅^�ǲ��ܳ�ֵ��</B></FONT></P>
			<P><FONT face="����" color="#cc3366"><B></FONT></FONT></B></P>
		</TD>
	</TR>
	<tr>
		<td style="WIDTH: 103px">��ֵ�[��̖</td>
		<td style="WIDTH: 141px">
			<asp:TextBox id="tbuserid" runat="server" Width="145px" MaxLength="14"></asp:TextBox></td>
		<td><FONT face="����">
				<asp:RequiredFieldValidator id="RequiredFieldValidator1" runat="server" ControlToValidate="tbuserid" ErrorMessage="*"></asp:RequiredFieldValidator>Ոݔ����Ҫ��ֵ���[��̖</FONT></td>
	</tr>
	<tr>
		<td style="WIDTH: 103px; HEIGHT: 3px">��ֵ���</td>
		<td style="WIDTH: 141px; HEIGHT: 3px">
			<asp:DropDownList id="ddtradetype" runat="server">
				<asp:ListItem Value="10" Selected="True">10Ԫ��100���ţ�</asp:ListItem>
				<asp:ListItem Value="30">30Ԫ��300���ţ�</asp:ListItem>
				<asp:ListItem Value="50">50Ԫ��500���ţ�</asp:ListItem>
				<asp:ListItem Value="100">100Ԫ��1000���ţ�</asp:ListItem>
				<asp:ListItem Value="200">200Ԫ����2000���ţ�</asp:ListItem>
				<asp:ListItem Value="300">300Ԫ����3000���ţ�</asp:ListItem>
				<asp:ListItem Value="500">500Ԫ����5000���ţ�</asp:ListItem>
				
			</asp:DropDownList></td>
		<td style="HEIGHT: 3px">
			<asp:RequiredFieldValidator id="Requiredfieldvalidator6" runat="server" ErrorMessage="*" ControlToValidate="ddtradetype"></asp:RequiredFieldValidator>Ո�x���ֵ���</td>
	</tr>
	<TR>
		<TD style="WIDTH: 103px; HEIGHT: 24px"><FONT face="����">Ոݔ����C�a</FONT></TD>
		<TD style="WIDTH: 141px; HEIGHT: 24px"><FONT face="����">
				<asp:TextBox id="tbverifycode" MaxLength="14" Width="48px" runat="server"></asp:TextBox><IMG id="imgVerify" style="WIDTH: 56px; CURSOR: hand; HEIGHT: 20px" onclick="this.src=this.src"
					height="20" alt="�����壿�c�����Q" src="../VerifyCode.aspx" width="56"></FONT></TD>
		<TD style="WIDTH: 210px" align="left" vAlign="middle"></FONT><FONT face="����">
				<asp:requiredfieldvalidator id="Requiredfieldvalidator2" runat="server" ErrorMessage="*" ControlToValidate="tbverifycode"></asp:requiredfieldvalidator>Ոݔ��DƬ�е��Ă�����</FONT></TD>
	</TR>
	<TR>
		<TD align="center" colSpan="3" height="17" style="HEIGHT: 17px"><FONT face="����">
				<asp:Label id="lbltradeno" runat="server" ForeColor="Red" Font-Bold="True" Visible="False"></asp:Label></FONT></TD>
	</TR>
	<TR>
		<TD colspan="3" align="center">
			<asp:Button id="btncreate" runat="server" Text="����ӆ��" CssClass="button_1"></asp:Button>
			<asp:Button id="btnpay" runat="server" Text="ǰ��֧������ֵ" Visible="False"></asp:Button>
		</TD>
	</TR>
</table>
<asp:RegularExpressionValidator id="RegularExpressionValidator1" runat="server" ErrorMessage="�[��̖��ʽ�����_" ValidationExpression="^[A-Za-z0-9]{4,14}$"
	ControlToValidate="tbuserid"></asp:RegularExpressionValidator>
<br>
<asp:regularexpressionvalidator id="RegularExpressionValidator3" runat="server" ErrorMessage="Ոݔ����λ����" ControlToValidate="tbverifycode"
	ValidationExpression="^\d{4}$"></asp:regularexpressionvalidator>
