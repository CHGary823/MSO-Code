<%@ Control Language="c#" AutoEventWireup="false" Codebehind="chareset.ascx.cs" Inherits="web.control.chareset" TargetSchema="http://schemas.microsoft.com/intellisense/ie5"%>
<table cellspacing="1" cellpadding="1" width="528" border="0">
	<TR>
		<TD colspan="3" style="HEIGHT: 290px">
			<P><b>�ھ��D��:</b></P>
			<P>�D����Ҫ�˳��[��ÿ����ɫ�������D��<span style="FONT-WEIGHT:bold;COLOR:#5d51f1"><%=Application["game.charesetcount"]%></span>��</P>
			<p>�D��Ҏ�t���£�</p>
			<P>1.��һ���D����Ҫ�ȼ���<span style="FONT-WEIGHT:bold;COLOR:#ff3333"><%=Application["game.charesetflv"]%></span>��������ÿ�Dһ������<span style="FONT-WEIGHT:bold;COLOR:#ff3333"><%=Application["game.charesetlvstep"]%></span>��</P>
			<P>2.��һ���D����Ҫ�[���<span style="FONT-WEIGHT:bold;COLOR:#ff3333"><%=Application["game.charesetfmoney"]%></span>Ԫ������ÿ�Dһ������<span style="FONT-WEIGHT:bold;COLOR:#ff3333"><%=Application["game.charesetmoneystep"]%></span>Ԫ</P>
			<P>3.��ɫ�D���ᣬ��ɫ�ȼ���<FONT color="#0000ff">1</FONT>��������<FONT color="#0000ff">1</FONT>��������<FONT color="#0000ff">12</FONT>�����ݞ�<FONT color="#0000ff">12</FONT>���w�|��<FONT color="#0000ff">12</FONT>�����}��<FONT color="#0000ff">12��</FONT></SPAN> 
				�����ɷ����c��<%=Application["game.charesetgivepoint"]%>*�D��</P>
			<P>4.<span style="FONT-WEIGHT:bold;COLOR:#5d51f1">15</span>�D����ÿ�D����100�����c��ϵ�y�ԄӼ����w�|</P>
			<P>5.<span style="FONT-WEIGHT:bold;COLOR:#5d51f1">30</span>�D�����_�ų����D��,ÿ�D���O��Կ�,�������������.ÿ�D������50�����c,ϵ�y�ԄӼ����w�|</P>
			<P><FONT face="����">ע��:30�D���_ʼÿ�D��Ҫ<span style="FONT-WEIGHT:bold;COLOR:#ff3333">50�|(5,000,000,000)</span>�[��Ż�<SPAN style="FONT-WEIGHT: bold; COLOR: #ff3333">500</SPAN>����,����ÿ����һ�D������<span style="FONT-WEIGHT:bold;COLOR:#ff3333">10�|(1,000,000,000)�[��Ż�500����</span>,�[���Ո����W���y��,ϵ�y���Ԅ�ȥ�W���y�пۿ�.</FONT></P>
		</TD>
	</TR>
	<tr>
		<td style="WIDTH: 103px">��ꑎ�̖</td>
		<td style="WIDTH: 120px"><strong><%=Session["userid"]%></strong></td>
		<td></td>
	</tr>
	<tr>
		<td style="WIDTH: 103px; HEIGHT: 14px">��ɫ�б�</td>
		<td style="WIDTH: 120px; HEIGHT: 14px">
			<asp:DropDownList id="ddchalist" runat="server"></asp:DropDownList></td>
		<td style="HEIGHT: 14px">
			<asp:RequiredFieldValidator id="Requiredfieldvalidator6" runat="server" ErrorMessage="*" ControlToValidate="ddchalist"></asp:RequiredFieldValidator>Ո�x����Ҫ�D���Ľ�ɫ</td>
	</tr>
	<TR>
		<TD align="center" colSpan="3" height="10">
			<asp:RadioButton id="rbmoney" runat="server" Text="�[���֧��" GroupName="paymode" Checked="True"></asp:RadioButton>
			<asp:RadioButton id="rbgold" runat="server" Text="����֧��(30�D�������ʹ��)" GroupName="paymode"></asp:RadioButton></TD>
	</TR>
	<TR>
		<TD colspan="3" align="center">
			<asp:Button id="btnedit" runat="server" Text="�_�J�D��" CssClass="button_1"></asp:Button>
		</TD>
	</TR>
</table>
