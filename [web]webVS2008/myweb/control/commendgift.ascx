<%@ Control Language="c#" AutoEventWireup="false" Codebehind="commendgift.ascx.cs" Inherits="web.control.commendgift" TargetSchema="http://schemas.microsoft.com/intellisense/ie5"%>
<table cellspacing="1" cellpadding="1" width="528" border="0">
	<TR>
		<TD colspan="3">
			<P><b>���]�����I��:</b></P>
			<P>�}�u�������e�����֣�ճ�N������Wվ��Փ����MSN��QQ�ȵط����e���c�˺�����ID���]�Ե�ַ�]���ᣬ�㌢���õ����</P>
			<P>����Ҏ�t��</P>
			<P>1.���������]��һ����ҵ��_<span style="FONT-WEIGHT:bold;COLOR:#ff3333">1</span>�D����Ϳ������@�e�Iȡ<span style="FONT-WEIGHT:bold;COLOR:#ff3333"><%=Application["game.commendmoney"].ToString()%></span>�[��ţ�<span style="FONT-WEIGHT:bold;COLOR:#ff3333"><%=Application["game.commendgold"].ToString()%></span>����</P>
			<P>2.ÿ���Iȡ�ᣬ�[��Ō����M��ľW���y��</P>
			<P>3.�����������]�Լ�ˢ�X���鵽���С̖ȫ���h��</P>
			<P>&nbsp;</P>
		</TD>
	</TR>
	<tr>
		<td style="WIDTH: 30%; HEIGHT: 14px">��ꑎ�̖</td>
		<td style="HEIGHT: 14px"><span style="FONT-WEIGHT:bold;COLOR:#5d51f1"><%=Session["userid"]%></span></td>
		<td style="HEIGHT: 14px"></td>
	</tr>
	<TR>
		<TD style="WIDTH: 233px; HEIGHT: 20px">�F�����]���˔�</TD>
		<TD style="WIDTH: 120px; HEIGHT: 20px"><span style="FONT-WEIGHT:bold;COLOR:#ff3333"><%=allppl%></span></TD>
		<TD style="HEIGHT: 20px"></TD>
	</TR>
	<TR>
		<TD style="WIDTH: 233px; HEIGHT: 19px">�ѽ�һ�D�˔�(���Iȡ��)</TD>
		<TD style="WIDTH: 120px; HEIGHT: 19px"><span style="FONT-WEIGHT:bold;COLOR:#ff3333"><%=resetppl%></span></TD>
		<TD style="HEIGHT: 19px"></TD>
	</TR>
	<TR>
		<TD align="center" colSpan="3" height="10"></TD>
	</TR>
	<TR>
		<TD align="center" colSpan="3" height="10">���]ϵ�y�yӋ�Y��������������Iȡ<span style="FONT-WEIGHT:bold;COLOR:#ff3333"><%=money%></span>�[��ţ�<span style="FONT-WEIGHT:bold;COLOR:#ff3333"><%=gold%></span>����</TD>
	</TR>
	<TR>
		<TD align="center" colSpan="3" height="10"></TD>
	</TR>
	<TR>
		<TD colspan="3" align="center">
			<asp:Button id="btnedit" runat="server" Text="�Iȡ����" CssClass="button_1"></asp:Button>
		</TD>
	</TR>
	<TR>
		<TD align="center" colSpan="3"></TD>
	</TR>
	<TR>
		<TD align="center" colSpan="3"><b>�����Z(������ҿ����Լ��޸ģ����]��朽Ӳ����޸ģ���t�������])</b></TD>
	</TR>
	<TR>
		<TD align="center" colSpan="3">
			<asp:TextBox id="tbcommendtext" onclick="this.select();" runat="server" Width="444px" TextMode="MultiLine"
				Height="154px"></asp:TextBox></TD>
	</TR>
	<TR>
		<TD align="center" colSpan="3"></TD>
	</TR>
</table>
