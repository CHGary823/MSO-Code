<%@ Control Language="c#" AutoEventWireup="false" Codebehind="itemtogold.ascx.cs" Inherits="web.control.itemtogold" TargetSchema="http://schemas.microsoft.com/intellisense/ie5"%>
<table cellspacing="1" cellpadding="1" width="528" border="0">
	<TR>
		<TD colspan="3" style="HEIGHT: 290px">
			<P><b>�����н���Ʒ����Ź���:</b></P>
			<P><FONT color="#000000"><FONT color="#0000ff"><STRONG>�н���Ʒ���Q���r��:</STRONG></FONT></FONT></P>
			<P>
			�I���S���C(����)&nbsp; ���Ճr��9</P>
		<P>�I���S���C(����)&nbsp; ���Ճr��90</P>
		<P>�I���S���C(ʮ����)&nbsp; ���Ճr�� 450</P>
		<P>�I���S���C���ɽ��ʹ��,��t�����ܻ���</P>
		<P>ע��: ��Ҫ���н���Ʒ׃�Q�ɽ��ŵ����,Ո���S���C�����ɫ�ٌ���Ʒ��,��Ҫ׃�Q���ٷŶ���,ϵ�y��һ����׃�Q�����ڴ˽�ɫ�ϵ������S���C�����</P>
		<P>����㲻��׃�Q���е��S���C,���Ԍ��S���C����ٌ��}��</P>
		</TD></TR>

	<tr>
		<td style="WIDTH: 103px">��ꑎ�̖</td>
		<td style="WIDTH: 120px"><strong><%=Session["userid"]%></strong></td>
		<td></td>
	</tr>
	<tr>
		<td style="WIDTH: 103px; HEIGHT: 12px">��ɫ�б�</td>
		<td style="WIDTH: 120px; HEIGHT: 12px">
			<asp:DropDownList id="ddchalist" runat="server"></asp:DropDownList></td>
		<td style="HEIGHT: 12px">
			<asp:RequiredFieldValidator id="Requiredfieldvalidator6" runat="server" ErrorMessage="*" ControlToValidate="ddchalist"></asp:RequiredFieldValidator>Ո�x���ɫ</td>
	</tr>
	<TR>
		<TD align="center" colSpan="3" height="10"><FONT face="����"></FONT></TD>
	</TR>
	<TR>
		<TD colspan="3" align="center">
			<asp:Button id="btnedit" runat="server" Text="�_�J׃�Q" CssClass="button_1"></asp:Button>
		</TD>
	</TR>
</table>
